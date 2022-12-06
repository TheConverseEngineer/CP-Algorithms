int N;
vector<int> adj[MAX_N];
int sub[MAX_N];

// DFS search to determine all subtree sizes
int dfsSize(int u, int p) {
    for (auto v : adj[u])
        if (v != p) sub[u] += dfsSize(v, u);
    return sub[u] + 1;
}

// Find centroid of a tree
int centroid(int u, int p) {
    for (auto v : adj[u])
        if (v != p and sub[v] > N/2) return centroid(v, u);
    return u;
}

// To use, first run dfsSize(0, -1) to populate the sub array
// Then use centroid(0, -1) to find the centroid of the tree
