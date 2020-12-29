#include <bits/stdc++.h>
using namespace std;

struct CentroidDecomposition {
	vector<vector<int>> edges;
	vector<bool> vis;
	vector<int> par;
	vector<int> sz;
	int n;

	void init(int s) {
		n = s;
		edges = vector<vector<int>>(n, vector<int>());
		vis = vector<bool>(n, false);
		par = vector<int>(n);
		sz = vector<int>(n);
	}

	void addEdge(int a, int b) {
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int findSize(int v, int p = -1) {
		if(vis[v]) return 0;
		sz[v] = 1;

		for(auto u: edges[v]) {
			if(u != p) {
				sz[v] += findSize(u,v);
			}
		}
		return sz[v];
	}

	int findCentroid(int v, int p, int cap) {
		for(auto u: edges[v]) {
			if(u != p) {
				if(!vis[u] and sz[u] > cap / 2) {
					return findCentroid(u, v, cap);
				}
			}
		}
		return v;
	}

	void initCentroid(int v = 0, int p = -1) {
		findSize(v);

		int c = findCentroid(v, -1, sz[v]);
		vis[c] = true;
		par[c] = p;

		for(auto u: edges[c]) {
			if(!vis[u]) {
				initCentroid(u, c);
			}
		}
	}
};