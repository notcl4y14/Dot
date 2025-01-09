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
		x = 0;
		y = 0;
		radius = 0;

		chunk = null;
		primCell = null;
		altCell = null;
	}

	public void fill (Cell cell) {
		CellBrush.x = x;
		CellBrush.y = y;
		CellBrush.cell = cell;
		CellBrush.chunk = chunk;
		CellBrush.fillCircle(radius);
	}

	public void fillPrim () {
		fill(primCell);
	}

	public void fillAlt () {
		fill(altCell);
	}
}
