package dot.cells.cells;

import java.awt.Color;

import dot.cells.types.CellPowder;

public class CellGravel extends CellPowder {
	public CellGravel () {
		super("gravel");
		this.color = new Color(0.40f, 0.40f, 0.40f, 1.0f);
	}
}
