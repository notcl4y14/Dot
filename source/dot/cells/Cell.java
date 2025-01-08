package dot.cells;

import java.awt.Color;

public class Cell {
	public String ID;
	public Color color;

	public boolean shouldUpdate;
	public boolean shouldDraw;
	
	public boolean isEmpty;
	public boolean isSolid;
	public boolean isPowder;
	public boolean isFluid;

	public Cell (String ID) {
		this.ID = ID;
		this.color = null;
		this.shouldUpdate = true;
		this.shouldDraw   = true;
		this.isEmpty  = false;
		this.isSolid  = false;
		this.isPowder = false;
		this.isFluid  = false;
	}

	public void update (CellChunk chunk, int x, int y) {}

	public boolean canPass (Cell cell) {
		return false;
	}
}
