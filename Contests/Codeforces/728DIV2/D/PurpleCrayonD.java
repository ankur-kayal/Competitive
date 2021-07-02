/*
stream Butter!
eggyHide eggyVengeance
I need U
xiao rerun when
 */
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;

import java.util.*;
import java.io.*;

public class PurpleCrayonD
{
    static final long MOD = 1000000007L;
    static ArrayDeque<Integer>[] edges;
    public static void main(String hi[]) throws Exception
    {
        fac = new long[420];
        invfac = new long[420];
        fac[0] = invfac[0] = 1L;
        for(int i=1; i < 420; i++)
        {
            fac[i] = (fac[i-1]*i)%MOD;
            invfac[i] = power(fac[i], MOD-2, MOD);
        }
        //dp[a][b] = prob. that a becomes 0 before b
        long[][] dp = new long[201][201];
        for(int a=0; a <= 200; a++)
            for(int b=0; b <= 200; b++)
                dp[a][b] = -1;
        for(int i=1; i <= 200; i++)
        {
            dp[0][i] = 1L;
            dp[i][0] = 0L;
        }
        for(int a=1; a <= 200; a++)
            for(int b=1; b <= 200; b++)
                dfs(a, b, dp);

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
        //read in tree
        BufferedReader infile = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(infile.readLine());
        int N = Integer.parseInt(st.nextToken());
        edges = new ArrayDeque[N+1];
        for(int i=1; i <= N; i++)
            edges[i] = new ArrayDeque<Integer>();
        for(int i=1; i < N; i++)
        {
            st = new StringTokenizer(infile.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            edges[a].add(b); edges[b].add(a);
        }
        long res = 0L;
        for(int a=1; a <= N; a++)
            for(int b=1; b < a; b++)
            {
                //stuff in here should be O(N)
                boolean[] seen = new boolean[N+1];
                int[] parent = new int[N+1];
                seen[a] = true; parent[a] = -1;
                ArrayDeque<Integer> q = new ArrayDeque<Integer>();
                q.add(a);
                while(q.size() > 0)
                {
                    int curr = q.poll();
                    for(int next: edges[curr])
                        if(!seen[next])
                        {
                            seen[next] = true;
                            parent[next] = curr;
                            q.add(next);
                        }
                }
                //if(a == 3 && b == 2)
                //    System.out.println(parent[1]+" "+parent[2]+" "+parent[3]);

                boolean[] onLine = new boolean[N+1];
                ArrayList<Integer> line = new ArrayList<Integer>();
                int currLineNode = b;
                while(currLineNode != a)
                {
                    line.add(currLineNode);
                    onLine[currLineNode] = true;
                    currLineNode = parent[currLineNode];
                    //System.out.println(currLineNode+" "+parent[currLineNode]);
                }
                line.add(a);
                onLine[a] = true;
                Collections.reverse(line);
                //get subtree sizes of each line node
                DSU union = new DSU(N+1);
                for(int v=1; v <= N; v++)
                    for(int next: edges[v])
                        if((!onLine[v] || !onLine[next]) && union.find(v) != union.find(next))
                            union.merge(v, next);
                for(int i=0; i < line.size(); i++)
                {
                    int distFromA = i;
                    int distFromB = line.size()-i-1;
                    long temp = (union.size[union.find(line.get(i))]*invfac[N])%MOD;
                    temp = (temp*fac[N-1])%MOD;
                    temp = (temp*dp[distFromA][distFromB])%MOD;
                    res += temp;
                    if(res >= MOD)
                        res -= MOD;
                }
            }
        System.out.println(res);
    }
    public static long dfs(int a, int b, long[][] dp)
    {
        if(dp[a][b] != -1)
            return dp[a][b];
        long res = (invfac[2]*dfs(a-1, b, dp))%MOD;
        res += (invfac[2]*dfs(a, b-1, dp))%MOD;
        if(res >= MOD)
            res -= MOD;
        return dp[a][b] = res;
    }
    /*
    static int time;
    static int[] enter, exit, depth;
    public static void dfs(int curr, int par)
    {
        enter[curr] = time++;
        for(int next: edges[curr])
            if(next != par)
            {
                depth[next] = depth[curr]+1;
                dfs(next, curr);
            }
        exit[curr] = time++;
    }
     */
    static long[] fac, invfac;
    public static long power(long x, long y, long p)
    {
        //0^0 = 1
        long res = 1L;
        x = x%p;
        while(y > 0)
        {
            if((y&1)==1)
                res = (res*x)%p;
            y >>= 1;
            x = (x*x)%p;
        }
        return res;
    }
}
/*
Root the tree on the first marked node (call it root)
node A must be marked before node B if and only if lca(A, B) = A
euler tour ranges to check ancestor
how to account for order of all nodes?

(alternate thinking)
Iterate over all n(n-1)/2 pairs that can cause an inversion
Get the "line" that connects node A and B
Do math on the line (all other nodes either lead to a line or are in subtree of A or B)
 */
class DSU
{
    public int[] dsu;
    public int[] size;

    public DSU(int N)
    {
        dsu = new int[N+1];
        size = new int[N+1];
        for(int i=0; i <= N; i++)
        {
            dsu[i] = i;
            size[i] = 1;
        }
    }
    //with path compression, no find by rank
    public int find(int x)
    {
        return dsu[x] == x ? x : (dsu[x] = find(dsu[x]));
    }
    public void merge(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        size[fy] += size[fx];
        dsu[fx] = fy;
    }
}