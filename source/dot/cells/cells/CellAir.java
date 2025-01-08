package dot.cells.cells;

import dot.cells.Cell;

public class CellAir extends Cell {
	public CellAir () {
		super("air");
		this.shouldUpdate = false;
		this.shouldDraw = false;
		this.isEmpty = true;
	}
}
