package dot.cells.cells;

import java.awt.Color;

import dot.cells.types.CellPowder;

public class CellSand extends CellPowder {
	public CellSand () {
		super("sand");
		this.color = new Color(255, 255, 0, 255);
	}
}
