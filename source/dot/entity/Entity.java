package dot.entity;

import dot.cells.Cell;
import dot.cells.CellChunk;

public class Entity {
	public double x;
	public double y;
	public int width;
	public int height;
	public double velX;
	public double velY;

	public Entity() {
		this.x = 0;
		this.y = 0;
		this.width = 0;
		this.height = 0;
		this.velX = 0;
		this.velY = 0;
	}

	public Cell[] getBottom (CellChunk chunk) {
		return chunk.getHorizontalCells((int)this.x, (int)this.x + this.width, (int)this.y + this.height);
	}

	public void applyVelocity () {
		this.x += this.velX;
		this.y += this.velY;
	}

	public boolean overlaps (Entity other) {
		return this.x < other.x + other.width
		    && other.x < this.x + this.width
			&& this.y < other.y + other.height
			&& other.y < this.y + this.height;
	}

	public void update (CellChunk chunk) {
		boolean stop = false;
		boolean inFluid = false;

		if (this.y >= 0 && this.y + this.height < chunk.height) {
			Cell[] bottomCells = this.getBottom(chunk);

			for (int i = 0; i < this.width; i++) {
				if (!bottomCells[i].isEmpty && !bottomCells[i].isFluid) {
					stop = true;
					break;
				} else if (bottomCells[i].isFluid) {
					inFluid = true;
				}
			}
		}

		if (stop) {
			this.velY = 0;
			this.y = (int) this.y;
		} else {
			this.velY += 0.01 * (inFluid ? 0.25 : 1);
		}
	}
}