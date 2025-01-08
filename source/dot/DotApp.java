package dot;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;

import dot.cells.CellChunk;
import dot.cells.cells.CellAir;
import dot.cells.cells.CellSand;
import dot.components.Display;
import dot.components.Runner;
import dot.components.Window;

public class DotApp {
	public Window window;
	public Display display;
	public Runner runner;

	public CellChunk cellChunk;

	public DotApp () {
		int windowWidth = DotOptions.CONTEXT_WIDTH * DotOptions.CONTEXT_SCALE;
		int windowHeight = DotOptions.CONTEXT_HEIGHT * DotOptions.CONTEXT_SCALE;

		// ==== Initializing Core Components ==== //
		window = new Window("Dot", windowWidth, windowHeight);
		window.setResizable(false);
		window.present();

		display = new Display();
		display.create(window);

		runner = new Runner(this);
		runner.looprate = 120;

		// ==== Initializing Game Components ==== //
		int worldWidth = DotOptions.CONTEXT_WIDTH;
		int worldHeight = DotOptions.CONTEXT_HEIGHT;

		cellChunk = new CellChunk(worldWidth, worldHeight);

		for (int i = 0; i < cellChunk.area; i++) {
			cellChunk.setCell(new CellAir(), i);
		}

		for (int i = 0; i < 10; i++) {
			cellChunk.setCell(new CellSand(), 10, i);
		}

		// ==== Starting the Game ==== //
		runner.start();
	}

	public void loop () {
		update();
		draw();
	}

	public void update () {
		if (runner.loopCount % 2 == 0)
			cellChunk.update();
	}

	public void draw () {
		Graphics2D graphics = (Graphics2D) display.getGraphics();
		Graphics2D graphicsOver = (Graphics2D) display.getGraphics();

		AffineTransform scale = new AffineTransform();
		scale.scale(DotOptions.CONTEXT_SCALE, DotOptions.CONTEXT_SCALE);
		graphics.transform(scale);

		// Clear Screen
		graphicsOver.setColor(Color.BLACK);
		graphicsOver.fillRect(0, 0, DotOptions.CONTEXT_WIDTH * DotOptions.CONTEXT_SCALE, DotOptions.CONTEXT_HEIGHT * DotOptions.CONTEXT_SCALE);

		// Draw Game Components
		cellChunk.render(graphics);

		// Draw FPS
		graphicsOver.setColor(new Color(0.0f, 0.0f, 0.0f, 0.75f));
		graphicsOver.fillRect(0, 0, 100, 10);

		graphicsOver.setColor(Color.WHITE);
		graphicsOver.drawString("FPS:" + runner.LPS, 0, 10);

		display.present();
		graphics.dispose();
	}
}