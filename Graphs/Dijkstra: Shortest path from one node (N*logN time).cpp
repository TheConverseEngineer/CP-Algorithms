/** Implementation of Dijkstra's Algorithm. Computes the shortest distance
 * between a specified node and all other nodes in a graph in O(N*logN) time.
 * 
 * @param n 		    number of nodes in graph	
 * @param max_dist      an arbitrarily large integer which represents no path to a node
 * @param start_node    the node that distances should be calculated from
 * @param adj		    a vector of size (n, ?), where each index i stores a vector containing all edges that include node i.
 *                      Each edge should be represented by a pair in the form (connected_node, length)
 * @param distance      An empty vector of size (n, n). This vector will be overwritten so that each point (i, j) represents 
 *                      the length of the shortest path from i to j (or max_dist if no path exists). 
 * */
 void dijkstra(int n, int max_dist, int start_node, const vector<vector<pair<int, int>>>& adj, vector<int>& distance) {
	for (int i = 0; i < n; i++) distance[i] = max_dist;
	distance[start_node] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq{};
	pq.push({0,start_node});
	while (!pq.empty()) {
		int dist, node; tie(dist, node) = pq.top(); 
		pq.pop();
		if (dist != distance[node]) continue;
		for (auto u : adj[node]) {
			if (dist+u.second < distance[u.first]) {
				distance[u.first] = dist+u.second;
				pq.push({distance[u.first],u.first});
			}
		}
	}
}
