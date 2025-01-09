package dot.cells;

import java.awt.Color;

public class Cell implements Cloneable {
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

	public Cell clone () {
		try {
			return (Cell) super.clone();
		} catch (CloneNotSupportedException e) {
			e.printStackTrace();
			return null;
		}
	}

	public void update (CellChunk chunk, int x, int y) {
		return;
	}

	public boolean canPass (Cell cell) {
		return false;
	}
}
