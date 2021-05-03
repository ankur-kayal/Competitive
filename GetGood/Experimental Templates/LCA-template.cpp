#include <bits/stdc++.h>
using namespace std;


struct LCABinaryLift {
	int lg;
	int n;
	vector<int> depth;
	vector<vector<int>> edges;
	vector<vector<int>> lift;

	void init(int sz) {
		n = sz;
		lg = ceil(log2(sz));
		depth = vector<int>(n);
		edges = vector<vector<int>>(n, vector<int>());
		lift = vector<vector<int>>(n, vector<int>(lg, -1));
	}

	void addEdge(int a, int b) {
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	void initLift(int v = 0) {
		depth[v] = 0;
		dfs(v, -1);

		for(int j=1;j<lg;j++) {
			for(int i=0;i<n;i++) {
				if(lift[i][j-1] != -1) {
					int par = lift[i][j-1];
					lift[i][j] = lift[par][j-1];
				}
			}
		}
	}

	void dfs(int v, int par) {
		lift[v][0] = par;
		for(auto u: edges[v]) {
			if(u != par) {
				depth[u] = depth[v] + 1;
				dfs(u, v);
			}
		}
	}

	int getKthAncestor(int v, int k) {
		for(int i=lg-1;i>=0;i--) {
			if(v == -1) return v;

			if((1 << i) <= k) {
				v = lift[v][i];
				k -= (1 << i);
			}
		}
		return v;
	}

	int getLCA(int a, int b) {
		if(depth[a] < depth[b]) swap(a,b);
		int d = depth[a] - depth[b];
		int v = getKthAncestor(a,d);

		if(v == b) {
			return v;
		}
		else {
			for(int i=lg-1;i>=0;i--) {
				if(lift[v][i] != lift[b][i]) {
					v = lift[v][i];
					b = lift[b][i];
				}
			}
			return lift[b][0];
		}
	}

	int getDistance(int a, int b) {
		int v = getLCA(a,b);
		return depth[a] + depth[b] - 2 * depth[v];
	}
};