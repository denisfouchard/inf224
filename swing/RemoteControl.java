import javax.swing.*;
import java.awt.event.ActionEvent;

public class RemoteControl extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea textArea;
    private JButton button1, button2, button3;
    private JMenuBar menuBar = new JMenuBar();
    private JMenu menu = new JMenu();
    private JToolBar toolBar = new JToolBar();


    public RemoteControl(){
        //macOS menu bar
        String os = System.getProperty("os.name").toLowerCase();
        if (os.contains("mac")) {
            // Operating System is macOS
            System.setProperty("apple.laf.useScreenMenuBar", "true");
        }

        // Layout elements
        JPanel windowsPanel = new JPanel();
        JPanel buttonPanel = new JPanel();
        textArea = new JTextArea("Bonjour", 20,20);
        JScrollPane textScroll = new JScrollPane(textArea);

        // Buttons
        button1 = new JButton("Button 1");
        button2 = new JButton("Button 2");
        button3 = new JButton("Button 3");
        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(button3);

        // Listeners
        button1.addActionListener( (ActionEvent event) -> textArea.setText("Button 1") );
        button2.addActionListener( (ActionEvent event) -> textArea.setText("Button 2") );
        button3.addActionListener( (ActionEvent event) -> textArea.setText("Button 3") );

        // Menu Bar
        menuBar.add(menu);
        menuBar.add(toolBar);

        // Panel layout
        windowsPanel.setLayout(new BoxLayout(windowsPanel, BoxLayout.Y_AXIS));
        windowsPanel.add(menuBar);
        //windowsPanel.add(textScroll);
        windowsPanel.add(new Canvas());
        windowsPanel.add(buttonPanel);

        // Display
        getContentPane().add(windowsPanel);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("TP Java Swing");
        pack();
        setVisible(true);

    }


}
