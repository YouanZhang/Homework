package banking.domain;
import java.util.*;

public class Bank {

    final static int MAXSIZE = 5;
    private Customer[] customers = new Customer[MAXSIZE];
    private int numberOfCustomers;
    private static Bank bankInstance = new Bank();

    private Bank() {
        numberOfCustomers = 0;
    }

    public void addCustomer(final String f, final String l) {
        customers[numberOfCustomers++] = new Customer(f, l);
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

    public void searchCustomers () {

    }
}
