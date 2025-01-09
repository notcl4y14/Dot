package dot.components;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import dot.DotInput;

public class MouseInput implements MouseListener, MouseMotionListener {

	public void mouseClicked(MouseEvent e) {
	}

	public void mousePressed(MouseEvent e) {
		DotInput.buttons.put(e.getButton(), true);
	}

	public void mouseReleased(MouseEvent e) {
		DotInput.buttons.put(e.getButton(), false);
	}

	public void mouseEntered(MouseEvent e) {
	}

	public void mouseExited(MouseEvent e) {
	}

	public void mouseDragged(MouseEvent e) {
		DotInput.mouseX = e.getX();
		DotInput.mouseY = e.getY();
	}

	public void mouseMoved(MouseEvent e) {
		DotInput.mouseX = e.getX();
		DotInput.mouseY = e.getY();
	}
	
}
