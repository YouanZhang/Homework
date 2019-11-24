package src.banking.DAO;

import java.io.*;
import java.util.*;
import src.banking.domain.*;
import src.banking.*;
import src.*;

public class CustomerDAO {
	private final static int NAME_SIZE = 20;
    private final static int RECORD_SIZE = 40;

    private RandomAccessFile raf;

    public CustomerDAO() {
        try{
            raf = new RandomAccessFile("customers.dat","rw");
        }
        catch(IOException ex){
            System.out.print("Error: "+ex);
            System.exit(0);
        }
    }

    public Customer readCustomers(long position) {
    	String f_name; String l_name;
        try{
        	raf.seek(position);
        	//System.out.printf("!!%d + %d\n",position);
        	f_name = FixedLengthStringIO.readFixedLengthString(NAME_SIZE, raf);
        	//System.out.printf("??%d\n",raf.getFilePointer());
        	f_name = f_name.trim();
        	l_name = FixedLengthStringIO.readFixedLengthString(NAME_SIZE, raf);
        	//System.out.printf("??%d\n",raf.getFilePointer());
        	l_name = l_name.trim();
        	Customer tmp = new Customer(f_name,l_name);
        	return tmp;
        }catch(IOException e) {
        	e.printStackTrace();
        	return new Customer("", "");
        }
    }
    
    public void writeCustomer(String f_name, String l_name) {
        try{
            raf.seek(raf.length());
            FixedLengthStringIO.writeFixedLengthString(f_name, NAME_SIZE, raf);
            FixedLengthStringIO.writeFixedLengthString(l_name, NAME_SIZE, raf);
        }
        catch (IOException ex){
            ex.printStackTrace();
        }
    }

    public RandomAccessFile getRaf(){
        return raf;
    }

    public void setRaf(RandomAccessFile r){
        raf = r;
    }

    public long length() throws IOException{
        return raf.length();
    }
    
    public long getSize() {
    	try {
    		long len = length();
    		//System.out.printf("%d, %d", len, len / (NAME_SIZE * 2 * 2));
			return len / (4 * NAME_SIZE);
    	}catch(IOException e){
    		e.printStackTrace();
    		return 0;
    	}
    }
    
    public boolean deleteFile(){
        boolean flag = false;
        try{
            raf.setLength(0);
            flag=true;
        }
        catch (IOException ex){}
        return flag;
    }
}
