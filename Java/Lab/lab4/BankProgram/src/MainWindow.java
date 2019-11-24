package src;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;
import src.banking.*;
import src.banking.domain.*;
import src.banking.DAO.*;
import javax.swing.*;
import javax.swing.border.*;


public class MainWindow extends JFrame {
    final static int NAME_SIZE = 20;
    final static int RECORD_SIZE = 40;

    //private RandomAccessFile raf;

    // define buttons and fields
    private JButton btnAdd = new JButton("Add");
    private JButton btnDel = new JButton("Del");
    private JButton btnSearch = new JButton("Search");
    private JButton btnSort = new JButton("Sort");
    private JTextField tfFirstName = new JTextField(NAME_SIZE);
    private JTextField tfLastName = new JTextField(NAME_SIZE);

    private Bank bank = Bank.getBank();

    @SuppressWarnings("unchecked")
    public MainWindow(){

    	bank.getPreBankCustomer(NAME_SIZE);
    	
        // button
        JPanel panButton = new JPanel();
        panButton.setLayout(new GridLayout(1, 4));
        panButton.add(btnAdd);
        panButton.add(btnDel);
        panButton.add(btnSearch);
        panButton.add(btnSort);

        // name
        JPanel panName = new JPanel();
        panName.setBorder(BorderFactory.createLoweredBevelBorder());
        JPanel p1 = new JPanel();
        p1.add(new JLabel("FirstName"), BorderLayout.CENTER);
        p1.add(tfFirstName, BorderLayout.EAST);
        JPanel p2 = new JPanel();
        p2.add(new JLabel("LastName"), BorderLayout.CENTER);
        p2.add(tfLastName, BorderLayout.EAST);
            
        // left panel
        JPanel panLeft = new JPanel();
        String[] customer = bank.getName();
        JList panList = new JList(customer);
        panList.setSize(300, 200);
        panList.setVisibleRowCount(10);
        panLeft.add(panList);

        // border of the left panel
        panLeft.setBorder(new TitledBorder("Customers List"));
        panList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        panList.setFixedCellHeight(20);
        panList.setFixedCellWidth(300);
        
        // right panel
        panName.setLayout(new GridLayout(2, 1, 5, 15));
        panName.add(p1);
        panName.add(p2);

        // right layout
        JPanel panRight = new JPanel();
        panRight.setLayout(new BorderLayout());
        panRight.add(panName, BorderLayout.CENTER);
        panRight.add(panButton, BorderLayout.SOUTH);

        //set panel and add to frame
        panLeft.setSize(300, 200);
        panRight.setSize(300, 200);
        add(panLeft, BorderLayout.CENTER);
        add(panRight, BorderLayout.EAST);

        // add button listener
        btnAdd.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                if ((!tfFirstName.getText().isEmpty()) || (!tfLastName.getText().isEmpty())){
                    bank.addCustomer(tfFirstName.getText(), tfLastName.getText());
                    String[] customer = bank.getName();
                    panList.setListData(customer);
                }
            }
        });

        // delete button listener
        btnDel.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                int tmp = panList.getSelectedIndex();
                if (tmp != -1){
                    bank.deleteCustomer(tmp);
                    String[] customer = bank.getName();
                    panList.setListData(customer);
                }  
            }
        });

        //search button listener
        btnSearch.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                String f = tfFirstName.getText(), l = tfLastName.getText();
                int tmp = bank.searchCustomer(f, l);
                if (tmp != -1) panList.setSelectedIndex(tmp);
            }
        });

        // sort button listener
        btnSort.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                bank.sortCustomers();
                String[] customer = bank.getName();
                panList.setListData(customer);
            }
        });
    }
    
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        MainWindow frame = new MainWindow();
        frame.setTitle("Bank Program");
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
    
}