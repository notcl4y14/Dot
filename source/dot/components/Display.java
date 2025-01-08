package dot.components;

import java.awt.Canvas;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

public class Display extends Canvas {
	public BufferStrategy buffer;

	public Display() {
		// Prevent keyboard listener from not working
		this.setFocusable(false);
	}

	public void create (Window window) {
		window.add(this);
		this.createBufferStrategy(2);
		this.buffer = this.getBufferStrategy();
	}

	public Graphics getGraphics () {
		return this.buffer.getDrawGraphics();
	}

	public void present () {
		this.buffer.show();
	}
}
