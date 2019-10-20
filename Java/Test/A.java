import java.io.*;
import java.util.*;
public class A{
    public static void main(String []arg){
        long a[] = new long[3];
        Scanner in = new Scanner(System.in);
        for (int Ca = in.nextInt(); Ca > 0; --Ca){
            for (int i = 0; i < 3; ++i) a[i] = in.nextLong();
            Arrays.sort(a);
            if (a[1] - a[0] >= a[2]){
                System.out.println(a[0] + a[2]);
            }
            else{
                System.out.println(a[1] + (a[2] - (a[1] - a[0])) / 2);
            }
        }
    }
}