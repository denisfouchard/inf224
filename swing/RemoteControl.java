import javax.swing.*;
import javax.swing.border.BevelBorder;
import java.awt.*;
import java.awt.event.ActionEvent;

public class RemoteControl extends JFrame {
    /**
     * Creates the main window for the application
     */
    private static final long serialVersionUID = 1L;
    private JPanel windowsPanel = new JPanel();
    private JLabel statusLabel = new JLabel();
    private JTextArea textArea;
    private JButton button1, button2, button3;
    private JMenu fileMenu, editMenu;
    private JMenuBar menuBar = new JMenuBar();
    private JToolBar toolBar = new JToolBar();
    private int CONNECTION_STATUS = 0;

    private Client client = null;


    public RemoteControl(){
        super();
        //macOS menu bar
        String os = System.getProperty("os.name").toLowerCase();
        if (os.contains("mac")) {
            // Operating System is macOS
            System.setProperty("apple.laf.useScreenMenuBar", "true");
        }

        // Server connection
        connect();
        MediaSelectionPanel selectionPanel = new MediaSelectionPanel(client);

        // Layout elements
        JPanel buttonPanel = new JPanel();


        // Buttons
        button1 = new JButton("Play");
        button2 = new JButton("Edit");
        button3 = new JButton("Delete");
        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(button3);

        // Listeners
        button1.addActionListener( (ActionEvent event) -> textArea.setText("Play") );
        button2.addActionListener( (ActionEvent event) -> textArea.setText("Edit") );
        button3.addActionListener( (ActionEvent event) -> textArea.setText("Delete") );

        // Menu Bar

        // FileMenu
        fileMenu = new JMenu("File");


        // Edit Menu
        editMenu = new JMenu("Edit");
        AbstractAction addMedia = new AbstractAction("Add media") {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Add media");
            }
        };
        AbstractAction removeMedia = new AbstractAction("Remove media") {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Remove media");
            }
        };


        AbstractAction addGroup = new AbstractAction("New group") {
            @Override
            public void actionPerformed(ActionEvent e) {
                selectionPanel.createGroup();
            }
        };
        AbstractAction deleteGroup = new AbstractAction("Delete group") {
            @Override
            public void actionPerformed(ActionEvent e) {
                selectionPanel.deleteGroup();
            }
        };
        editMenu.add(addMedia);
        editMenu.add(removeMedia);
        editMenu.addSeparator();
        editMenu.add(addGroup);
        editMenu.add(deleteGroup);


        // Menu bar
        menuBar.add(fileMenu);
        menuBar.add(editMenu);
        menuBar.add(toolBar);

        // Panel layout
        windowsPanel.add(menuBar);
        setJMenuBar(menuBar);
        windowsPanel.setLayout(new BoxLayout(windowsPanel, BoxLayout.Y_AXIS));
        windowsPanel.add(selectionPanel);
        windowsPanel.add(buttonPanel);

        // Status bar
        JPanel statusPanel = new JPanel();
        // JLabel statusLabel = new JLabel("Status");
        windowsPanel.add(statusPanel, BorderLayout.SOUTH);
        statusPanel.setPreferredSize(new Dimension(windowsPanel.getWidth(), 16));
        statusPanel.setLayout(new BoxLayout(statusPanel, BoxLayout.X_AXIS));
        statusLabel.setHorizontalAlignment(SwingConstants.LEFT);
        statusPanel.add(statusLabel);







        // Add selection panel

        // Display
        getContentPane().add(windowsPanel);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Media Player");
        setPreferredSize(new Dimension(1280,720));
        setMinimumSize(new Dimension(1000, 500));
        pack();
        setVisible(true);

    }

    public void setStatusBar(String status){
        statusLabel.setText(status);
    }

    public void connect(){
        try {
            client = new Client();
            CONNECTION_STATUS = 1;
            // Set connection status
            setStatusBar("Client connected to "+client.getHost()+":"+client.getPort());
        }
        catch (Exception e) {
            Object[] options = { "Try again", "Cancel"};
            int result = JOptionPane.showOptionDialog(this, e.getMessage(), "Server connection error", JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE,
                    null, options, null);
            if (result == JOptionPane.YES_OPTION){
                connect();
            } else {
                System.exit(1);
            }
        }

    }




}
