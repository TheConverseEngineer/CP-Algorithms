// Note that this sample uses 1-indexed nodes!
// The default max number of nodes is only 50002!

int jump[17][50002], depth[50002];
vi adj[50002];
int N;

void dfs(int u, int p, int d=0) {
	jump[0][u] = p; depth[u] = d;
	for(int v : adj[u])
		if (v!=p) dfs(v, u, d+1);
}

void buildJump() {
	FOR(i, 1, 17) {
		FOR(node, 1, N+1)
			jump[i][node] = jump[i-1][jump[i-1][node]];
	} 
}

int LCA(int a, int b) {
	if(depth[a] < depth[b]) swap(a, b);
	for (int i = 16; i >= 0; i--) if (depth[jump[i][a]] >= depth[b]) a = jump[i][a];
	if (a == b) return a;
	for (int i = 16; i >= 0; i--) {
		if (jump[i][a] != jump[i][b]) {
			a = jump[i][a];
			b = jump[i][b];
		}
	}
	return jump[0][a];
}
