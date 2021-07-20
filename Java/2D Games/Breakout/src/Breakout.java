import java.awt.Dimension; //Used to get dimension and size of user's screen
import java.awt.Frame;
import java.awt.Toolkit; //Used to get dimension and size of user's screen
import java.awt.event.KeyListener;

import javax.swing.JFrame;

public class Breakout {
	public static JFrame mFrame = new JFrame();
	
	public static void main(String[] args) {
		setFrame();
		
		
		
		
		
		
	}
	
	private static void setFrame()
	{
		mFrame.setTitle("Breakout");
		
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		double width = screenSize.getWidth() / 3;
		double height = screenSize.getHeight() / 2;
		mFrame.setBounds(0, 0, (int)width, (int)height);
		
		 mFrame.addKeyListener((KeyListener) new Frame());
		
		
		mFrame.setVisible(true);
		mFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
