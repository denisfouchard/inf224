package swing;

import javax.swing.*;

public class ControlButtonPanel {
    /**
     * Creates the panel with the buttons for the control of the media
     */
    private JButton playButton, editButton, deleteButton;
    private JPanel buttonPanel = new JPanel();
    private Client client;

    public ControlButtonPanel(RemoteControl remoteControl, Client client){
        super();
        this.client = client;
        buttonPanel.setLayout(new BoxLayout(buttonPanel, BoxLayout.X_AXIS));
        // Buttons
        playButton = new JButton("Play");
        editButton = new JButton("Edit");
        deleteButton = new JButton("Delete");
        // disable buttons
        playButton.setEnabled(false);
        editButton.setEnabled(false);
        deleteButton.setEnabled(false);

        // add buttons to panel
        buttonPanel.add(playButton);
        buttonPanel.add(editButton);
        buttonPanel.add(deleteButton);

        // setup listeners
        playButton.addActionListener(e -> {
            client.send("PLAY " + remoteControl.getSelectedMedia());
        });
        editButton.addActionListener(e -> {
            client.send("EDITMEDIA " + remoteControl.getSelectedMedia());
        });
        deleteButton.addActionListener(e -> {
            client.send("DELETEMEDIA " + remoteControl.getSelectedMedia());
        });
    }

    public JPanel getButtonPanel() {
        return buttonPanel;
    }

    public JButton getPlayButton() {
        return playButton;
    }

    public JButton getEditButton() {
        return editButton;
    }

    public JButton getDeleteButton() {
        return deleteButton;
    }

}
