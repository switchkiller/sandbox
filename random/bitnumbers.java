import java.util.Scanner;
import java.math.BigInteger;
public class bitnumbers{
  public static void main(String[] args) {
    int K;
    long rem = 0;
    BigInteger N = BigInteger.ONE;
    N=12345678;
    for (int i = 2; i <= 25; i++)
      rem = N.mod(BigInteger.valueOf(k));
    if (rem == 0) System.out.println("YES");
    else System.out.println("NO");
  }
}
