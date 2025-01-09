package dot.cells;

public class CellChunkBase {
	public int width;
	public int height;
	public int area;
	public Cell[] cells;

	public CellChunkBase (int width, int height) {
		this.width = width;
		this.height = height;
		this.area = width * height;
		this.cells = new Cell[this.area];
	}

	// ======== Cells ======== //
	public Cell getCell (int x, int y) {
		return this.getCell(y * width + x);
	}

	public Cell getCell (int index) {
		return this.cells[index];
	}

	public void setCell (Cell cell, int x, int y) {
		this.setCell(cell, y * width + x);
	}

	public void setCell (Cell cell, int index) {
		this.cells[index] = cell;
	}

	// ================================ //

	public void swapCells (int srcX, int srcY, int destX, int destY) {
		Cell srcCell = this.getCell(srcX, srcY);
		Cell destCell = this.getCell(destX, destY);

		this.setCell(srcCell, destX, destY);
		this.setCell(destCell, srcX, srcY);
	}
	
	// ================================ //

	public void fill (Cell cell) {
		for (int i = 0; i < this.area; i++) {
			this.setCell(cell.clone(), i);
		}
	}
}
