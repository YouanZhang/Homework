package banking;

public class Customer{
    private String firstName = "";
    private String lastName = "";
    Account account = new Account();

    public Customer(String _firstName, String _lastName) {
        firstName = _firstName; lastName = _lastName;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName(){
        return lastName;
    }

    public Account getAccount(){
        return account;
    }

    public void setAccount(Account acct){
        this.account = acct;
    }

    
}