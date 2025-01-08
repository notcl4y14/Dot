package dot.cells.cells;

import java.awt.Color;

import dot.cells.Cell;
import dot.cells.CellChunk;

public class CellSand extends Cell {
	public CellSand () {
		super("sand");
		this.color = new Color(255, 255, 0, 255);
		this.isPowder = true;
	}

	public void update (CellChunk chunk, int x, int y) {
		if (y == chunk.height - 1)
			return;
		
		Cell sCell = chunk.getCell(x, y + 1);

		if (this.canPass(sCell)) {
			chunk.swapCells(x, y, x, y + 1);
		}

		Cell swCell = x == 0 ? null : chunk.getCell(x - 1, y + 1);
		Cell seCell = x == chunk.width - 1 ? null : chunk.getCell(x + 1, y + 1);

		if (this.canPass(swCell)) {
			chunk.swapCells(x, y, x - 1, y + 1);
		} else if (this.canPass(seCell)) {
			chunk.swapCells(x, y, x + 1, y + 1);
		}
	}

	public boolean canPass (Cell cell) {
		return cell == null ? false :
			cell.isEmpty;
	}
}
