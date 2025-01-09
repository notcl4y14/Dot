package dot.rendering;

import java.awt.Graphics2D;
import java.awt.RenderingHints;

public class GraphicsInitializer {
	public static boolean antialias = true;

	public static void apply (Graphics2D graphics) {
		graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, antialias ? RenderingHints.VALUE_ANTIALIAS_ON : RenderingHints.VALUE_ANTIALIAS_OFF);
	}
}
