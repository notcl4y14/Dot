package dot.cells.cells;

import java.awt.Color;

import dot.cells.types.CellSolid;

public class CellStone extends CellSolid {
	public CellStone () {
		super("stone");
		this.color = new Color(0.5f, 0.5f, 0.5f, 1.0f);
	}
}
