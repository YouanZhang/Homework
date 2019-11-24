package src.banking.domain;
import java.lang.*;

public class OverdraftException extends Exception {
    private double deficit;

    public OverdraftException(String message, double _deficit) {
        super(message);
        deficit = _deficit;
    }
    public double getDeficit() {
        return deficit;
    }
}