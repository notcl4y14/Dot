package dot.cells.types;

import dot.cells.Cell;
import dot.cells.CellChunk;

public class CellPowder extends Cell {
	public CellPowder (String ID) {
		super(ID);
		this.isPowder = true;
	}

	public void update (CellChunk chunk, int x, int y) {
		if (y == chunk.height - 1)
			return;
		
		int vx = 0;
		int vy = 0;
		
		Cell sCell = y == chunk.height - 1 ? null : chunk.getCell(x, y + 1);
		Cell swCell = x == 0 ? null : chunk.getCell(x - 1, y + 1);
		Cell seCell = x == chunk.width - 1 ? null : chunk.getCell(x + 1, y + 1);

		if (this.canPass(sCell)) {
			vx = 0;
			vy = 1;
		} else if (this.canPass(swCell)) {
			vx = -1;
			vy = 1;
		} else if (this.canPass(seCell)) {
			vx = 1;
			vy = 1;
		}

		chunk.swapCells(x, y, x + vx, y + vy);
	}

	public boolean canPass (Cell cell) {
		return cell == null ? false :
			cell.isEmpty;
	}
}
