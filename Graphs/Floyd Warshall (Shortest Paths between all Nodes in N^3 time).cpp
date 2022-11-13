/** Implementation of the Floyd-Warshall Algorithm. Computes the shortest distance
 * between all nodes in a graph in O(N^3) time.
 * 
 * @param n 			number of nodes in graph
 * @param max_dist		an arbitrarily high number that represents the absence of a path
 * 		NOTE: max_dist should be less than half of the integer limit to avoid overflow
 * @param adj			a vector of size (n, n), where each point (i, j) represents 
 * 						the length of the path from i to j (or 0 if no path exists)
 * @param distance		an empty vector of size (n, n). This method will overrite this vector
 * 						using the same convention established by the adj parameter.
 * */
void floyd_warshall(int n, int max_dist, const vector<vector<int>>& adj, vector<vector<int>>& distance) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) distance[i][j] = 0;
			else if (adj[i][j]) distance[i][j] = adj[i][j];
			else distance[i][j] = max_dist;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
		}
	}
}
