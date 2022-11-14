/** Implementation of Disjoint Set Union. See dedicated file for more details. Needed for Kruskall's algorithm to work */
struct DSU {
	vector<int> size;
	DSU(int _n) { size.assign(_n, -1); }
	int getRep(int a) { return size[a] < 0 ? a : size[a] = getRep(size[a]); }
	bool connected(int a, int b) { return getRep(a) == getRep(b); }
	int compSize(int a) { return -size[getRep(a)]; }
	bool connect(int a, int b) {  // union by size
		a = getRep(a); b = getRep(b);
		if (a == b) return false;
		if (size[a] > size[b]) swap(a, b);
		size[a] += size[b];
    		size[b] = a;
		return true;
	}
};

/** Implementation of Kruskall's Algorithm. Computes the minimum total edge length required to form a 
 *  minimum spanning tree on a graph in M*logM time. For dense graphs, refer to Prim's algorithm instead.
 *
 *  @param n      the total number of nodes in the graph
 *  @param edges  vector consisting of all nodes in a graph. Note that this algorithm will sort this list.
 *                all edges should be in the form (length, (node 1, node 2))
 *  @return       the minimum required length to construct an MST
 */
int kruskall(int n, vector<pair<int, pair<int, int>>>& edges) {
	sort(edges.begin(), edges.end());
	DSU dsu(n); int ret{0};
	for (pair<int, pair<int, int>> edge : edges) {
		if (dsu.connect(edge.second.first, edge.second.second)) ret += edge.first;
	}
	return ret;
}
