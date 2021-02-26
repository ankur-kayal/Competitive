import java.util.*;
import java.io.*;

public class PRIGAME {

    public static void main(String[] args) {
        FastScanner fs=new FastScanner();
        int T=fs.nextInt();
        int[] isPrime = new int[1000100];
        int[] countNumberOfPrimes = new int[1000100];
        Arrays.fill(isPrime, 1);
        Arrays.fill(countNumberOfPrimes, 0);
        isPrime[0] = isPrime[1] = 0;
        for(int i=2;i*i<=1000000;i++) {
            if(isPrime[i] == 1)
            for(int j=i*i;j<=1000000;j+=i) {
                isPrime[j] = 0;
            }
        }
        for(int i=2;i<=1000000;i++) {
            countNumberOfPrimes[i] = countNumberOfPrimes[i-1];
            if(isPrime[i] == 1) {
                countNumberOfPrimes[i]++;
            }
        }
        PrintWriter out = new PrintWriter(System.out);
        for (int tt=0; tt<T; tt++) {
            int x = fs.nextInt();
            int y = fs.nextInt();
            if(countNumberOfPrimes[x] <= y) {
                out.println("Chef");
            }
            else {
                out.println("Divyam");
            }

        }
        out.close();
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