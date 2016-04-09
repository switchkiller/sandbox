import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class CoinJamv {

    public static void main(String[] args) throws FileNotFoundException {
        final Scanner in = new Scanner(new FileInputStream("in"));
//        final Scanner in = new Scanner(System.in);
        System.setOut(new PrintStream("out"));
        final int t = in.nextInt();
        for (int caseNum = 1; caseNum <= t; caseNum++) {
            final int n = in.nextInt();
            final int intent = in.nextInt();
            BigInt start = (1 << (n - 1)) + 1;
            BigInt end = (1 << n) - 1;
            int found = 0;
            System.out.println(String.format("Case #%d: ", caseNum));
            for (BigInt currentNum = start; currentNum <= end; currentNum++) {
                if (currentNum.mod(2) == 0) {
                    continue;
                }
                BidInt[] values = getValues(currentNum);
                if (values != null) {
                    System.out.print(currentNum.toString());
                    for (int base = 2; base <= 10; base++) {
                        System.out.print(" " + values[base]);
                    }
                    System.out.println();
                    found++;
                    if (found == intent) {
                        return;
                    }
                }
            }
        }
    }

    public static long firstNontrivalDivisor(long n) {
        for (long i = 2; i <= Math.sqrt(n + 1); i++) {
            if (n % i == 0) {
                return i;
            }
        }
        return -1;
    }

    public static long[] getValues(BigInt n) {
        final long[] value = new long[11];
        final String binaryFormat = n.toString();
        for (int base = 2; base <= 10; base++) {
            long sum = 0;
            for (int i = binaryFormat.length() - 1, j = 0; i >= 0; i--, j++) {
                if (binaryFormat.charAt(i) == '1') {
                    sum += Math.pow(base, j);
                }
            }
            final long v = firstNontrivalDivisor(sum);
            value[base] = v;
            if (v == -1) {
                return null;
            }
        }
        return value;
    }
}