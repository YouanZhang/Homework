package banking;

public class CheckingAccount extends Account {
    private double overdraftProtection;

    public CheckingAccount(double balance) {
        super(balance);
    }

    public CheckingAccount(double balance, double protect) {
        super(balance);
        this.overdraftProtection = protect;
    }

    public boolean withdraw(double amt) {
        if (super.balance >= amt) {
            super.balance -= amt;
            return true;
        }
        if (super.balance + overdraftProtection > amt) {
            overdraftProtection -= amt - super.balance;
            super.balance = 0;
            return true;
        }
        return false;
    }

    public double getOverdraftProtection() {
        return overdraftProtection;
    }

}
