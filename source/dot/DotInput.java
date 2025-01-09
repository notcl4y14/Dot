package dot;

import java.util.HashMap;

public class DotInput {
	public static HashMap<Integer, Boolean> keys = new HashMap<>();
	public static HashMap<Integer, Boolean> buttons = new HashMap<>();

	public static double mouseX = 0;
	public static double mouseY = 0;

	public static int MOUSE_LEFT = 1;
	public static int MOUSE_MIDDLE = 2;
	public static int MOUSE_RIGHT = 3;

	public static boolean isKeyDown (int key) {
		try {
			return keys.get(key);
		} catch (Exception e) {
			return false;
		}
	}

	public static boolean isMouseDown (int button) {
		try {
			return buttons.get(button);
		} catch (Exception e) {
			return false;
		}
	}
}
