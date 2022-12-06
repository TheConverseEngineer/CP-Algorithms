// Creates array par, where par[u] represents u's parents in the centroid decomposition 
// par[root] = -1
// Note that tAdj represents the adjacency list, and will be emptied during construction

set<int> tAdj[MAX_N];
int par[MAX_N], subsz[MAX_N];

int subSz(int u, int p) {
	subsz[u] = 1;
	for (int v : adj[u]) 
		if (v != p) subsz[u] += subSz(v, u);
	return subsz[u];
}
int findCentroid(int u, int p, int n) {
	for (int v: tAdj[u]) 
		if (v != p && subsz[v] > n/2) return findCentroid(v, u, n);
	return u;
}
void buildCD(int u, int p) {
	int centroid = findCentroid(u, p, subSz(u, p));
	par[centroid] = p;
	for (int v : tAdj[centroid]) { 
		tAdj[centroid].erase(v);
		tAdj[v].erase(centroid);
		buildCD(v, centroid);
	}
}
