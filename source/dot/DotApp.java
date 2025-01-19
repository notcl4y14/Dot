package dot;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.event.KeyEvent;
import java.awt.geom.AffineTransform;

import dot.cells.CellWorld;
import dot.cells.cells.CellAir;
import dot.cells.cells.CellGravel;
import dot.cells.cells.CellSand;
import dot.cells.cells.CellSoil;
import dot.cells.cells.CellStone;
import dot.cells.cells.CellWater;
import dot.components.Display;
import dot.components.KeyboardInput;
import dot.components.MouseInput;
import dot.components.Runner;
import dot.components.Window;
import dot.controls.CellCursor;
import dot.entity.Entity;
import dot.rendering.GraphicsInitializer;

public class DotApp {
	public Window window;
	public Display display;
	public Runner runner;

	public CellWorld cellChunk;
	public CellCursor cellCursor;
	public Entity entity;

	public DotApp () {
		int windowWidth = DotOptions.CONTEXT_WIDTH * DotOptions.CONTEXT_SCALE;
		int windowHeight = DotOptions.CONTEXT_HEIGHT * DotOptions.CONTEXT_SCALE;

		// ==== Initializing Core Components ==== //
		window = new Window("Dot", windowWidth, windowHeight);
		window.setResizable(false);
		window.addKeyListener(new KeyboardInput());
		window.present();

		display = new Display();
		display.create(window);
		display.addMouseListener(new MouseInput());
		display.addMouseMotionListener(new MouseInput());

		runner = new Runner(this);
		runner.looprate = 120;

		// ==== Initializing Game Components ==== //
		int worldWidth = DotOptions.CONTEXT_WIDTH;
		int worldHeight = DotOptions.CONTEXT_HEIGHT;

		cellChunk = new CellWorld(worldWidth, worldHeight);
		cellChunk.fill(new CellAir());

		cellCursor = new CellCursor();
		cellCursor.setChunk(cellChunk);
		cellCursor.setPrimaryCell(new CellSand());
		cellCursor.setAlternativeCell(new CellAir());
		cellCursor.setRadius(9);

		entity = new Entity();
		entity.width = 8;
		entity.height = 16;

		// ==== Starting the Game ==== //
		runner.start();
	}

	// ================================ //

	public void loop () {
		update();
		draw();
	}

	public void update () {
		// Cell World
		if (runner.loopCount % 2 == 0)
			cellChunk.update();
		
		// Cell Cursor
		if (DotInput.isKeyDown(KeyEvent.VK_1)) {
			cellCursor.setPrimaryCell(new CellSand());
		} else if (DotInput.isKeyDown(KeyEvent.VK_2)) {
			cellCursor.setPrimaryCell(new CellStone());
		} else if (DotInput.isKeyDown(KeyEvent.VK_3)) {
			cellCursor.setPrimaryCell(new CellWater());
		} else if (DotInput.isKeyDown(KeyEvent.VK_4)) {
			cellCursor.setPrimaryCell(new CellSoil());
		} else if (DotInput.isKeyDown(KeyEvent.VK_5)) {
			cellCursor.setPrimaryCell(new CellGravel());
		}
		
		cellCursor.x = (int) DotInput.mouseX / DotOptions.CONTEXT_SCALE;
		cellCursor.y = (int) DotInput.mouseY / DotOptions.CONTEXT_SCALE;

		if (DotInput.isMouseDown(DotInput.MOUSE_LEFT)) {
			cellCursor.fillPrimaryCell();
		}

		if (DotInput.isMouseDown(DotInput.MOUSE_RIGHT)) {
			cellCursor.fillAlternativeCell();
		}

		entity.update(cellChunk);

		if (DotInput.isKeyDown(KeyEvent.VK_UP)) {
			entity.velY = -1;
		}

		entity.applyVelocity();
	}

	public void draw () {
		Graphics2D g1 = (Graphics2D) display.getGraphics();
		Graphics2D g2 = (Graphics2D) display.getGraphics();

		// g1.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		// g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

		GraphicsInitializer.apply(g1);
		GraphicsInitializer.apply(g2);

		AffineTransform scale = new AffineTransform();
		scale.scale(DotOptions.CONTEXT_SCALE, DotOptions.CONTEXT_SCALE);
		
		g1.transform(scale);

		// Clear Screen
		g2.setColor(Color.BLACK);
		g2.fillRect(0, 0, DotOptions.CONTEXT_WIDTH * DotOptions.CONTEXT_SCALE, DotOptions.CONTEXT_HEIGHT * DotOptions.CONTEXT_SCALE);

		// Draw Game Components
		cellChunk.render(g1);
		// cellChunk.renderAlive(g1);

		g1.setColor(Color.WHITE);
		g1.fillRect((int)entity.x, (int)entity.y, entity.width, entity.height);

		g1.setColor(new Color(1.0f, 1.0f, 1.0f, 0.25f));
		g1.fillArc(cellCursor.x - cellCursor.radius, cellCursor.y - cellCursor.radius, cellCursor.radius * 2, cellCursor.radius * 2, 0, 360);

		// Draw FPS
		g2.setColor(new Color(0.0f, 0.0f, 0.0f, 0.75f));
		g2.fillRect(0, 0, 100, 10);

		g2.setColor(Color.WHITE);
		g2.drawString("FPS:" + runner.LPS, 0, 10);

		display.present();
		g1.dispose();
		g2.dispose();
	}
}