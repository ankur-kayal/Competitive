import java.io.*;
import java.util.*;

class GROUPS {

    public static void main(String[] args) {
        FastScanner fs=new FastScanner();
        int T=fs.nextInt();
        for (int tt=0; tt<T; tt++) {
            char[] s = (fs.next() + '0').toCharArray();

            int groups = 0;

            boolean one = false;

            for(char i: s) {
                if(i == '1') {
                    one = true;
                }
                else {
                    if(one) {
                        groups++;
                        one = false;
                    }
                }
            }

            System.out.println(groups);
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