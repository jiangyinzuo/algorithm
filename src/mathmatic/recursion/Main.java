import java.util.*;
import java.math.*;

public class Main {
    public static void recursion(BigInteger[] res) {
        res[1] = new BigInteger("1");
        res[2] = new BigInteger("5");
        BigInteger x;
        for (int i = 3; i <= 100; i++) {
            x = BigInteger.valueOf(i * i);
            res[i] = x.multiply(res[i - 2]).add(x).add(res[i - 1]);
        }
    }

    public static void main(String[] args) {
        BigInteger[] res = new BigInteger[109];
        recursion(res);
        Scanner in = new Scanner(System.in);
        int n;
        while (in.hasNext()) {
            n = in.nextInt();
            System.out.println(res[n]);
        }
        in.close();
    }
}
