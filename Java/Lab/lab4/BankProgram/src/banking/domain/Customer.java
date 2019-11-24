package src.banking.domain;

import java.util.*;

public class Customer implements Comparable <Customer>{
    private String firstName;
    private String lastName;
    ArrayList <Account> account = new ArrayList <Account> ();

    public Customer(String f, String l) {
        firstName = f; lastName = l;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName(){
        return lastName;
    }

    public void addAccount(Account acc) {
        account.add(acc);
    }

    public Account getAccount(int index){
        return account.get(index);
    }

    public int getNumOfAccounts() {
        return account.size();
    }

    public int compareTo(Customer b){
        return (getLastName().compareTo(b.getLastName()) == 0 ? getFirstName().compareTo(b.getFirstName()) : getLastName().compareTo(b.getLastName()));
    }
}
