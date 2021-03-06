package banking;

public class Bank {

    final static int MAXSIZE = 5;
    private Customer[] customers = new Customer[MAXSIZE];
    private int numberOfCustomers;

    public Bank() {
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
    
}
