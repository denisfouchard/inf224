import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.*;
import java.lang.reflect.Array;
import java.util.ArrayList;

public class MediaSelectionPanel extends JPanel {
    /**
     * Creates two horizontally aligned scroll panels for both groups and medias, with specific methods for each
     * element.
     */
    private JScrollPane mediaScrollPane;
    private JScrollPane groupScrollPane;
    private Client client = null;

    private JList<String> mediaListSelection;
    private JList<String> groupListSelection;
    private DefaultListModel<String> mediaModel;
    private DefaultListModel<String> groupModel;

    public MediaSelectionPanel(Client client){
        super();
        this.client = client;
        this.setLayout(new BoxLayout(this, BoxLayout.X_AXIS));
        mediaModel = new DefaultListModel<>();
        groupModel = new DefaultListModel<>();

        mediaListSelection = new JList<>(mediaModel);
        groupListSelection = new JList<>(groupModel);

        mediaListSelection.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        groupListSelection.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        groupModel.addElement("Test group");
        mediaModel.addElement("Test media");

        mediaScrollPane = new JScrollPane(mediaListSelection);
        groupScrollPane = new JScrollPane(groupListSelection);

        groupListSelection.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (groupListSelection.getSelectedValue() != null) {
                    String selectedGroup = groupListSelection.getSelectedValue();
                    String mediasFromGroup = client.send("SHOWGROUP " + selectedGroup);

                }
            }
        });



        this.add(groupScrollPane);
        this.add(mediaScrollPane);
    }

    public void createGroup(){
        String groupName = JOptionPane.showInputDialog(this, "Group's name : ");
        String res = client.send("CREATEGROUP " + groupName);
        groupModel.addElement(groupName);
    }

    public void deleteGroup(){
        groupModel.remove(groupListSelection.getSelectedIndex());
    }

    public void createMedia(){
        String groupName = JOptionPane.showInputDialog(this, "Group's name : ");
        String res = client.send("CREATEGROUP " + groupName);
        groupModel.addElement(groupName);
    }





}
