package dot.cells.types;

import dot.cells.Cell;

public class CellSolid extends Cell {
	public CellSolid (String ID) {
		super(ID);
		this.isSolid = true;
		this.shouldUpdate = false;
	}
}
