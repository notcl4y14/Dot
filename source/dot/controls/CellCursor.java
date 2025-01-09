package dot.controls;

import dot.cells.Cell;
import dot.cells.CellBrush;
import dot.cells.CellChunk;

public class CellCursor {
	public int x;
	public int y;
	public int radius;

	public CellChunk chunk;
	public Cell primCell;
	public Cell altCell;

	public CellCursor () {
		this.x = 0;
		this.y = 0;
		this.radius = 0;

		this.chunk = null;
		this.primCell = null;
		this.altCell = null;
	}

	// ================================ //
	
	public void setChunk (CellChunk chunk) {
		this.chunk = chunk;
	}

	public void setPrimaryCell (Cell cell) {
		this.primCell = cell;
	}

	public void setAlternativeCell (Cell cell) {
		this.altCell = cell;
	}

	public void setRadius (int radius) {
		this.radius = radius;
	}

	// ================================ //
	
	public void fill (Cell cell) {
		CellBrush.x = this.x;
		CellBrush.y = this.y;
		CellBrush.cell = cell;
		CellBrush.chunk = this.chunk;
		CellBrush.fillCircle(this.radius);
	}

	public void fillPrimaryCell () {
		this.fill(primCell);
	}

	public void fillAlternativeCell () {
		this.fill(altCell);
	}
}
