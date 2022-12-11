int tin[MAXN], tout[MAXN];
int tSize[MAXN]; // Size of subtree, including node
vi adj[MAXN];

int timer = 0;
int dfs(int u, int p) {
	tin[u] = timer;
	tSize[u] = 1;
	for (int v : adj[u]) {
		if (v != p) {
			timer++; 
			tSize[u] += dfs(v, u);
		}
	}
	timer++; tout[u] = timer;
	return tSize[u];
}

bool isChild(int c, int a) {
	return (tin[a] < tin[c]) and (tout[a] > tout[c]);
}
