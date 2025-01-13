package dot.components;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import dot.DotInput;

public class KeyboardInput implements KeyListener {

	public void keyTyped(KeyEvent e) {
	}

	public void keyPressed(KeyEvent e) {
		DotInput.keys.put(e.getKeyCode(), true);
	}

	public void keyReleased(KeyEvent e) {
		DotInput.keys.put(e.getKeyCode(), false);
	}

}