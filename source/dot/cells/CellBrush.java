package dot.cells;

public class CellBrush {
	public static int x = 0;
	public static int y = 0;

	public static Cell cell = null;
	public static CellChunk chunk = null;

	public static void fill () {
		chunk.setCell(cell.clone(), x, y);
	}

	public static void fillRect (int x2, int y2) {
		for (int _x = x; _x < x2; _x++) {
			for (int _y = y; _y < y2; _y++) {
				chunk.setCell(cell.clone(), _x, _y);
			}
		}
	}

	public static void fillCircle (int radius) {
		int x1 = x - radius;
		int y1 = y - radius;
		int x2 = x + radius;
		int y2 = y + radius;

		// https://stackoverflow.com/a/17163962/22146374
		for (int _x = x1; _x < x2; _x++) {
			for (int _y = y1; _y < y2; _y++) {
				boolean check = ((_x - x) * (_x - x) + (_y - y) * (_y - y)) <= radius * radius;

				if (!check)
					continue;
				
				try {
					chunk.setCell(cell.clone(), _x, _y);
				} catch (Exception e) {
					continue;
				}
			}
		}
	}
}
