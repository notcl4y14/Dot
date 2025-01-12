package dot.cells;

import java.awt.Color;

public class Cell implements Cloneable {
	public String ID;
	public Color color;

	public boolean shouldUpdate;
	public boolean shouldDraw;
	
	public boolean isEmpty;
	public boolean isSolid;
	public boolean isPowder;
	public boolean isFluid;

	public boolean alive;
	public int aliveCount;

	public static int aliveCountMax = 100;

	public Cell (String ID) {
		this.ID = ID;
		this.color = null;
		this.shouldUpdate = true;
		this.shouldDraw   = true;
		this.isEmpty  = false;
		this.isSolid  = false;
		this.isPowder = false;
		this.isFluid  = false;
		this.alive      = true;
		this.aliveCount = 0;
	}

	public Cell clone () {
		try {
			return (Cell) super.clone();
		} catch (CloneNotSupportedException e) {
			e.printStackTrace();
			return null;
		}
	}

	public void update (CellChunk chunk, int x, int y) {
		return;
	}

	public void turnAlive (CellWorld world, int x, int y) {
		this.alive = true;
		this.aliveCount = 0;
		world.nextChunks(y * world.width + x);
	}

	public void turnIdle () {
		if (this.aliveCount > Cell.aliveCountMax) {
			this.alive = false;
		} else {
			this.aliveCount++;
		}
	}

	public boolean canPass (Cell cell) {
		return false;
	}

	public boolean getUpdatable () {
		return this.shouldUpdate && this.alive;
	}
}
