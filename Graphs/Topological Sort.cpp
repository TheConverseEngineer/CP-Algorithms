// after[u] represents the adj list of u (directed)

vi topsort;
void dfs(int u) {
	for (pii v : after[u]) {
		if (!vis[v.first]) {
			vis[v.first] = 1;
			dfs(v.first);
		}	
	}
	topsort.emplace_back(u);
}

int main() {
  FOR (i, 0, N) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(i);
		}
	}
	reverse(all(topsort));
}
