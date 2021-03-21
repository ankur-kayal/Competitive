import java.io.*;
import java.util.*;

public class NOTIME {

    public static void main(String[] args) {
        FastScanner fs=new FastScanner();
        int n = fs.nextInt();
        int H = fs.nextInt();
        int x = fs.nextInt();

        String ans = "NO";
        int[] times = fs.readArray(n);
        for(int time: times) {
            if (x + time >= H) {
                ans = "YES";
            }
        }
        System.out.println(ans);
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