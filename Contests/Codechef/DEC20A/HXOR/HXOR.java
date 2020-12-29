import java.io.*;
import java.util.*;

/*


Test 1:

Input:
3
5 3
1 2 3 4 5
2 100000000
14513658 458955478
3 1
2 3 1

Output:
0 0 0 0 1 
1 461795117 
0 1 1

*/

public class HXOR {

    public static void main(String[] args) {
        FastScanner fs=new FastScanner();
        int T=fs.nextInt();
        PrintWriter out = new PrintWriter(System.out);
        for (int tt=0; tt<T; tt++) {
            int n = fs.nextInt();
            int x = fs.nextInt();
            int[] a = fs.readArray(n);
            int[] bitCount = new int[31];
            ArrayDeque<Integer>[] bitPosition = new ArrayDeque[31];
            int[] pow2 = new int[31];
            pow2[0] = 1;
            for(int i=1;i<31;i++) {
                pow2[i] = pow2[i-1] * 2;
            }
            for(int i=0;i<31;i++) {
                bitPosition[i] = new ArrayDeque<Integer>();
            }

            // System.out.println(Integer.numberOfTrailingZeros(Integer.highestOneBit(0)));
            // preprocess the bit count and bit position
            for(int i=0;i<n;i++) {
                for(int bit=0;bit<=Integer.numberOfTrailingZeros(Integer.highestOneBit(a[i]));bit++) {
                    if((a[i] & pow2[bit]) != 0) {
                        bitCount[bit]++;
                        bitPosition[bit].add(i);
                    }
                }
            }

            boolean solved = false;
            for(int i=0;i<n-1;i++) {
                if(a[i] == 0) continue;
                for(int bit=Integer.numberOfTrailingZeros(Integer.highestOneBit(a[i]));bit>=0;bit--) {
                    // System.out.println(bit + " " + a[i]);
                    if((a[i] & pow2[bit]) != 0) {
                        if(bitCount[bit] > 1) {
                            bitPosition[bit].removeFirst();
                            int index = bitPosition[bit].getFirst();
                            bitPosition[bit].removeFirst();
                            a[i] = a[i] ^ pow2[bit];
                            a[index] = a[index] ^ pow2[bit];
                            bitCount[bit] -= 2;
                        }
                        else {
                            a[i] = a[i] ^ pow2[bit];
                            a[n - 1] = a[n - 1] ^ pow2[bit];
                            bitPosition[bit].removeFirst();
                            bitPosition[bit].add(n - 1);
                        }
                        --x;
                        if(x == 0) {
                            solved = true;
                        }
                    }
                    if(solved) {
                        break;
                    }
                }
                if(solved) {
                    break;
                }
            }

            if(x == 1 || (n == 2 && x % 2 == 1)) {
                a[n - 1] = a[n - 1] ^ 1;
                a[n - 2] = a[n - 2] ^ 1;
            }


            for(int i=0;i<n;i++) {
                out.print(a[i] + " ");
            }
            out.println();
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