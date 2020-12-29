import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class Restore {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int maxN = 1400000;
		int[] seive = new int[maxN + 1];
		Arrays.fill(seive, 1);
		seive[0] = seive[1] = 0;
		for(int i=2;i*i<= maxN;i++) {
			if(seive[i] == 1) {
				for(int j=i*i;j<=maxN;j+=i) {
					seive[j] = 0;
				}
			}
		}
		ArrayList<Integer> primes = new ArrayList<Integer>();
		for(int i=2;i<=maxN;i++) {
			if(seive[i] == 1) {
				primes.add(i);
			}
		}
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n = fs.nextInt();
			int[] b = fs.readArray(n);
			int[] ans = new int[n];
			Arrays.fill(ans, -1);
			int ind = 0;
			for(int i=0;i<n;i++) {
				if(ans[b[i] - 1] == -1) {
					ans[i] = primes.get(ind);
					ans[b[i] - 1] = ans[i];
					ind++;
				}
				else {
					ans[i] = ans[b[i] - 1];
				}
			}
			for(int i=0;i<n;i++) {
				System.out.print(ans[i] + " ");
			}
			System.out.println();

		}
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}