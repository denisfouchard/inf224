import javax.swing.*;
import java.awt.event.ActionEvent;

public class RemoteControl extends JFrame {
    JTextArea textArea = new JTextArea("Bonjour", 20,20);
    JButton button1 = new JButton("Button 1");
    JButton button2 = new JButton("Button 2");
    JButton button3 = new JButton("Button 3");

    public RemoteControl(){
        JPanel windowsPanel = new JPanel();
        JPanel buttonPanel = new JPanel();
        windowsPanel.setLayout(new BoxLayout(windowsPanel, BoxLayout.Y_AXIS));
        // Buttons
        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(button3);
        // Listeners
        button1.addActionListener( (ActionEvent event) -> textArea.setText("Button 1") );
        button2.addActionListener( (ActionEvent event) -> textArea.setText("Button 2") );
        button3.addActionListener( (ActionEvent event) -> textArea.setText("Button 3") );

        windowsPanel.add(textArea);
        windowsPanel.add(buttonPanel);

        getContentPane().add(windowsPanel);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Bib Bip");
        pack();
        setVisible(true);

    }


}
