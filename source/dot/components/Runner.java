package dot.components;

import dot.DotApp;

public class Runner implements Runnable {

	public DotApp app;
	public Thread thread;
	public boolean running;

	public int looprate;
	public int loopCount;
	public int LPS;
	public int lpsCounter;
	public long lpsTime;
	public int lpsUpdate;

	public Runner (DotApp app) {
		this.app = app;
		this.thread = new Thread(this);
		this.running = false;

		this.looprate   = 0;
		this.loopCount  = 0;
		this.LPS        = 0;
		this.lpsCounter = 0;
		this.lpsTime    = 0;
		this.lpsUpdate  = 1000;
	}

	public synchronized void start () {
		this.running = true;
		this.lpsTime = System.currentTimeMillis();
		this.thread.start();
	}

	public void stop () {
		this.running = false;
		
		try {
			this.thread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	public void run() {
		while (this.running) {
			this.app.loop();

			this.loopCount++;
			this.lpsCounter++;

			if (System.currentTimeMillis() >= this.lpsTime) {
				this.lpsTime += this.lpsUpdate;
				this.LPS = this.lpsCounter;
				this.lpsCounter = 0;
			}

			try {
				Thread.sleep(1000 / looprate);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	
}
