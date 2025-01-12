package dot.cells.types;

import dot.cells.Cell;
import dot.cells.CellChunk;
import dot.cells.CellWorld;

public class CellFluid extends Cell {
	public CellFluid (String ID) {
		super(ID);
		this.isFluid = true;
	}

	public void update (CellChunk chunk, int x, int y) {
		int vx = 0;
		int vy = 0;
		
		Cell sCell = y == chunk.height - 1 ? null : chunk.getCell(x, y + 1);
		Cell wCell = x == 0 ? null : chunk.getCell(x - 1, y);
		Cell eCell = x == chunk.width - 1 ? null : chunk.getCell(x + 1, y);

		boolean goLeft = Math.random() < 0.5;

		if (this.canPass(sCell)) {
			vx = 0;
			vy = 1;
		} else if (goLeft && this.canPass(wCell)) {
			vx = -1;
			vy = 0;
		} else if (!goLeft && this.canPass(eCell)) {
			vx = 1;
			vy = 0;
		}

		chunk.swapCells(x, y, x + vx, y + vy);

		if (vx != 0 || vy != 0) {
			this.turnAlive((CellWorld) chunk, x, y);
		} else {
			this.turnIdle();
		}
	}

	public boolean canPass (Cell cell) {
		return cell == null ? false :
			cell.isEmpty;
	}
}
