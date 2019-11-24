package src.banking.domain;

import java.util.*;
import java.io.IOException;
import java.io.RandomAccessFile;
import src.banking.DAO.*;
import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;

public class Bank
{
	final static int MAXSIZE = 10;
    private Customer[] customers = new Customer[MAXSIZE];
    private int numberOfCustomers;
    private static Bank bankInstance = new Bank();
    private CustomerDAO customerFile = new CustomerDAO();

    private Bank() {
        numberOfCustomers = 0;
    }

    public void addCustomer(final String f, final String l) {
        customers[numberOfCustomers++] = new Customer(f, l);
        customerFile.writeCustomer(f,l);
    }

    public int getNumOfCustomers() {
        return numberOfCustomers;
    }

    public Customer getCustomer(final int index) {
        return customers[index];
    }
    
    public static Bank getBank() {
        return bankInstance;
    }

    public void sortCustomers () {
        Arrays.sort(customers, 0, numberOfCustomers);
    }
    
    public int searchCustomer(String f, String l){
        Customer tmp = new Customer(f, l);
        for (int i = 0;i < customers.length; i++){
            if (tmp.compareTo(customers[i]) == 0){
            	return i;
            }
        }
        return -1;
    }

    public String[] getName(){
        String[] tmp = new String[10];
        for (int i = 0;i < numberOfCustomers; i++)
            tmp[i] = customers[i].getFirstName() + "," + customers[i].getLastName();
        return tmp;
    }

    public void deleteCustomer(int index){
        for (int i=index+1;i<numberOfCustomers;i++)
            customers[i-1]=customers[i];
        customers[numberOfCustomers-1]=new Customer("", "");
        numberOfCustomers--;
        customerFile.deleteFile();
        try{
            RandomAccessFile raf=new RandomAccessFile("customers.dat","rw");
            customerFile.setRaf(raf);
        }catch(IOException ex){
            System.out.print("Error: "+ex);
            System.exit(0);
        }
        for (int i=0;i<numberOfCustomers;i++){
            String f=customers[i].getFirstName();
            String l=customers[i].getLastName();
            customerFile.writeCustomer(f,l);
        }
    }
    public void getPreBankCustomer(int NAME_SIZE) {
    	try{
    		numberOfCustomers = (int)customerFile.getSize();
    		//System.out.printf("%d", numberOfCustomers);
    		for(int i = 0; i < numberOfCustomers; i++) {
    			customers[i] = customerFile.readCustomers(i * NAME_SIZE * 2 * 2);
    		}
    	}catch(Exception e) {
    		e.printStackTrace();
    	}
    }
}
