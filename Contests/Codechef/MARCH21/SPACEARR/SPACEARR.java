import java.io.*;
import java.util.*;

class SPACEARR {

    public static void main(String[] args) {
        FastScanner fs=new FastScanner();
        int T=fs.nextInt();
        for (int tt=0; tt<T; tt++) {
            int n = fs.nextInt();
            int[] a = fs.readArray(n);
            ruffleSort(a);

            long maximumMoves = 0;
            for(int i=0;i<n;i++) {
                if(i + 1 < a[i]) {
                    maximumMoves = 0;
                    break;
                }
                else {
                    maximumMoves += (long)a[i] - i - 1;
                }
            }  

            String ans = maximumMoves % 2 == 0 ? "Second" : "First";
            System.out.println(ans);          
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