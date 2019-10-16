import java.util.*;
import java.math.*;

//Naive Algorithm

public class Main{
	public static void main(String args[]){
		Scanner ob = new Scanner(System.in);
		BigInteger []a = new BigInteger[103];

		while(ob.hasNext()) {
			int n = 0;
			while (true){
				int x = ob.nextInt();
				(x == -999999) break;
				a[n++] = BigInteger.valueof(x);
			}
			BigInteger val = BigInteger.valueof(-999999);
			for (int i = 0; i < n; i++){
				BigInteger ret = a[i];
				val = val.max(ret);
				for (int j = i + 1; j < n; j++){
					ret = ret.multiply(a[j]);
					val = val.max(ret);
				}
			}
			System.out.println(val);
		}

	}

}