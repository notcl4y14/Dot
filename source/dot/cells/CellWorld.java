package dot.cells;

import java.awt.Color;
import java.awt.Graphics2D;

public class CellWorld extends CellChunk {
	public int[] chunkCells;

	public CellWorld (int width, int height) {
		super(width, height);
		this.chunkCells = new int[this.area];
	}

	// ======== Loop Methods ======== //

	public void update () {
		this.updateChunks();
	}

	public void render (Graphics2D graphics) {
		super.render(graphics);
	}

	public void renderAlive (Graphics2D graphics) {
		for (int i = 0; i < this.area; i++) {
			Cell cell = this.getCell(i);

			if (!cell.shouldDraw)
				continue;

			int x = i % this.width;
			int y = i / this.width;
			
			graphics.setColor(this.chunkCells[i] == 1 ? new Color(0.0f, 0.0f, 0.5f, 0.5f) : new Color(0.0f, 0.0f, 0.0f, 0.0f));
			graphics.fillRect(x, y, 1, 1);
		}
	}

	// ======== Chunk Loop Methods ======== //

	public void updateChunks () {
		for (int x = 0; x < this.width; x++) {
			for (int y = this.height - 1; y >= 0; y--) {
				int index = y * this.width + x;
				int cellIndex = this.chunkCells[index];

				if (cellIndex == 0)
					continue;
				
				Cell cell = this.cells[index];

				int cellX = index % this.width;
				int cellY = index / this.width;

				if (!cell.shouldUpdate)
					continue;
				
				cell.update(this, cellX, cellY);

				// TODO: Remove this and call this only from Cell.update() if needed
				if (!cell.shouldUpdate)
					this.removeChunk(cellIndex);
			}
		}
	}

	// ======== Chunks Management ======== //

	public void createChunk (int index) {
		if (index < 0 || index >= this.area)
			return;
		this.chunkCells[index] = 1;
	}

	public void removeChunk (int index) {
		this.chunkCells[index] = 0;
	}

	public void moveChunk (int indexSrc, int indexDest) {
		this.chunkCells[indexSrc] = 0;
		this.chunkCells[indexDest] = 1;
	}

	public void swapChunks (int indexSrc, int indexDest) {
		int srcChunk = this.chunkCells[indexSrc];
		int destChunk = this.chunkCells[indexDest];
		
		this.chunkCells[indexSrc] = destChunk;
		this.chunkCells[indexDest] = srcChunk;
	}

	public void nextChunks (int index) {
		int x = index % this.width;
		int y = index / this.width;

		// Sides
		this.createChunk(y * this.width + (x - 1));
		this.createChunk(y * this.width + (x + 1));
		this.createChunk((y - 1) * this.width + x);
		this.createChunk((y + 1) * this.width + x);
		// Corners
		this.createChunk((y - 1) * this.width + (x - 1));
		this.createChunk((y - 1) * this.width + (x + 1));
		this.createChunk((y + 1) * this.width + (x - 1));
		this.createChunk((y + 1) * this.width + (x + 1));
	}

	// ======== Cell Management ======== //

	public void setCell (Cell cell, int index) {
		super.setCell(cell, index);

		if (cell.getUpdatable()) {
			this.createChunk(index);
		} else {
			this.removeChunk(index);
		}
	}

	public void swapCells (Cell cell, int srcX, int srcY, int destX, int destY) {
		super.swapCells(srcX, srcY, destX, destY);

		int indexSrc = srcY * this.width + srcX;
		int indexDest = destY * this.width + destX;
		this.swapChunks(indexSrc, indexDest);
	}
}
