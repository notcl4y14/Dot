package dot.cells;

import java.awt.Graphics2D;

public class CellChunk extends CellChunkBase {
	public CellChunk (int width, int height) {
		super(width, height);
	}

	public Cell[] getHorizontalCells (int x1, int x2, int y) {
		int width = x2 - x1;

		Cell[] cells = new Cell[width];

		for (int i = 0; i < width; i++) {
			Cell cell = this.getCell(x1 + i, y);
			cells[i] = cell;
		}

		return cells;
	}

	public Cell[] getVerticalCells (int x, int y1, int y2) {
		int height = y2 - y1;

		Cell[] cells = new Cell[height];

		for (int i = 0; i < height; i++) {
			Cell cell = this.getCell(x, y1 + i);
			cells[i] = cell;
		}

		return cells;
	}

	public void update () {
		for (int x = 0; x < this.width; x++) {
			for (int y = this.height - 1; y >= 0; y--) {
				Cell cell = this.getCell(x, y);

				if (!cell.shouldUpdate)
					continue;
				
				cell.update(this, x, y);
			}
		}
	}

	public void render (Graphics2D graphics) {
		for (int i = 0; i < this.area; i++) {
			Cell cell = this.getCell(i);

			if (!cell.shouldDraw)
				continue;

			int x = i % this.width;
			int y = i / this.width;
			
			graphics.setColor(cell.color);
			graphics.fillRect(x, y, 1, 1);
		}
	}
}
