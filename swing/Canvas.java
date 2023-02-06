import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Canvas extends JPanel {
    private int last_x, last_y;

    public Canvas() {
        setBackground(Color.white);
        addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                last_x = e.getX();
                last_y = e.getY();
            }
        });
        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e) {
                int x = e.getX();
                int y = e.getY();
                var g = getGraphics();
                g.drawLine(last_x, last_y, x, y);
                last_x = x;
                last_y = y;
            }
        });
    }
}
