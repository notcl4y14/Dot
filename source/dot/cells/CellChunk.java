package dot.cells;

import java.awt.Color;
import java.awt.Graphics2D;

public class CellChunk extends CellChunkBase {
	public CellChunk (int width, int height) {
		super(width, height);
	}

	public void update () {
		for (int x = 0; x < this.width; x++) {
			for (int y = this.height - 1; y >= 0; y--) {
				Cell cell = this.getCell(x, y);

				if (!cell.shouldUpdate)
					continue;
				
				cell.update(this, x, y);
			}
		}
	}

	public void render (Graphics2D graphics) {
		for (int i = 0; i < this.area; i++) {
			Cell cell = this.getCell(i);

			if (!cell.shouldDraw)
				continue;

			int x = i % this.width;
			int y = i / this.width;
			
			// Color color = (x + y) % 2 == 0 ? new Color(0.25f, 0.25f, 0.25f, 1.0f) : new Color(0.75f, 0.75f, 0.75f, 1.0f);
			Color color = cell.color;
			graphics.setColor(color);
			graphics.fillRect(x, y, 1, 1);
		}
	}
}
