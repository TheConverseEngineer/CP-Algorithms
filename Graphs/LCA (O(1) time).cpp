#define MAXN 50005
namespace tree {
	vi adj[MAXN];
	pii tour[18][2*MAXN];
	int tin[MAXN];

	int timer = 0;
	void dfs(int u, int p, int depth) {
		tin[u] = timer;
		tour[0][timer++] = {depth, u};
		for (int v : adj[u]) {
			if (v != p) {
				dfs(v, u, depth+1);
				tour[0][timer++] = {depth, u};
			}
		}
	}

	void build() {
		for (int i = 1; i < 18; i++) {
			for (int j = 0; j + (1<<i) <= 2*MAXN; j++) {
				tour[i][j] = min(tour[i-1][j], tour[i-1][j + (1<<(i-1))]);
			}
		}
	}

	int LCA(int a, int b) {
		if (tin[a] > tin[b]) swap(a, b);
		int i = __builtin_clz(1) - __builtin_clz(tin[b]-tin[a]+1);
		return min(tour[i][tin[a]], tour[i][tin[b] - (1<<i) + 1]).second; 
	}
}	
using namespace tree;
