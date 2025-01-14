package dot.cells.cells;

import java.awt.Color;

import dot.cells.types.CellPowder;

public class CellSoil extends CellPowder {
	public CellSoil () {
		super("soil");
		this.color = new Color(128, 50, 0, 255);
	}
}
