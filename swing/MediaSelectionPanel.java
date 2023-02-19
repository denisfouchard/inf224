package swing;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.*;

public class MediaSelectionPanel extends JPanel {
    /**
     * Creates two horizontally aligned scroll panels for both groups and medias, with specific methods for each
     * element.
     */
    private String selectedGroup, selectedMedia;
    private JScrollPane mediaScrollPane;
    private JScrollPane groupScrollPane;
    private Client client = null;
    private JList<String> mediaListSelection;
    private JList<String> groupListSelection;
    private DefaultListModel<String> mediaModel;
    private DefaultListModel<String> groupModel;

    public MediaSelectionPanel(Client client, RemoteControl remoteControl){
        super();
        this.client = client;
        this.setLayout(new BoxLayout(this, BoxLayout.X_AXIS));
        mediaModel = new DefaultListModel<>();
        groupModel = new DefaultListModel<>();

        mediaListSelection = new JList<>(mediaModel);
        groupListSelection = new JList<>(groupModel);
        mediaListSelection.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        groupListSelection.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        // Select first group by default if it exists
        if (groupListSelection.getModel().getSize() > 0){
            groupListSelection.setSelectedIndex(1);
            selectedGroup = groupListSelection.getSelectedValue();
        }

        // Send request to server for group list and show all of its medias
        updateGroupList();
        updateMediaList();


        mediaScrollPane = new JScrollPane(mediaListSelection, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        groupScrollPane = new JScrollPane(groupListSelection, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        mediaScrollPane.setPreferredSize(new Dimension(200, 200));
        groupScrollPane.setPreferredSize(new Dimension(200, 200));

        // Add buttons to groupScrollPane
        JButton addGroupButton = new JButton("Add group");

        addGroupButton.addActionListener(e -> {
            createGroup();
        });

        groupScrollPane.add(addGroupButton);

        // Make groupScrollPane and mediaScrollPane resizable with a custom divider
        JSplitPane splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, groupScrollPane, mediaScrollPane);
        splitPane.setOneTouchExpandable(true);
        splitPane.setDividerLocation(200);
        splitPane.setResizeWeight(0.5);
        splitPane.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
        this.add(splitPane);

        groupListSelection.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (groupListSelection.getSelectedValue() != null) {
                    selectedGroup = groupListSelection.getSelectedValue();
                    remoteControl.setSelectedGroup(selectedGroup);
                    updateMediaList();
                }
            }
        });

        mediaListSelection.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (mediaListSelection.getSelectedValue() != null) {
                    selectedMedia = mediaListSelection.getSelectedValue();
                    remoteControl.setSelectedMedia(selectedMedia);
                    String res = client.send("SHOWMEDIA " + selectedMedia);
                    // parse res to get medias with ; as separator
                    String[] mediaAttributes = res.split(";");
                }
            }
        });

    }

    public void createGroup(){
        /**
        * Creates a group with a name given by the user
         */
        String groupName = JOptionPane.showInputDialog(this, "Group name : ");
        String res = client.send("CREATEGROUP " + groupName);
        groupModel.addElement(groupName);
    }

    public void deleteGroup(){
        groupModel.remove(groupListSelection.getSelectedIndex());
    }

    public void updateGroupList() {
        String res = client.send("SHOWALLGROUPS");
        // parse res to get medias with ; as separator
        String[] groups = res.split(";");
        groupModel.clear();
        for (String group : groups) {
            groupModel.addElement(group);
        }
    }

    public void updateMediaList() {
        String res = client.send("LISTGROUP " + selectedGroup);
        // parse res to get medias with ; as separator
        String[] medias = res.split(";");
        mediaModel.clear();
        for (String media : medias) {
            mediaModel.addElement(media);
        }

    }
}
