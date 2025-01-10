package dot.cells.cells;

import java.awt.Color;

import dot.cells.types.CellFluid;

public class CellWater extends CellFluid {
	public CellWater () {
		super("water");
		this.color = new Color(0, 128, 128, 128);
	}
}
