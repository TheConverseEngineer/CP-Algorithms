/** Implementation of the Floyd-Warshall Algorithm. Computes the shortest distance
 * between all nodes in a graph in O(N^3) time.
 * 
 * @param n 			number of nodes in graph		
 * @param adj			a vector of size (n, n), where each point (i, j) represents the length of the
 *  				path from i to j (or an arbitrarily large integer if no path exists). This vector will be 
 * 				ovewritten. NOTE: the large integer should be less than half of the integer limit to avoid overflow
 * */
void floyd_warshall(int n, vector<vector<int>>& distance) {
	for (int i = 0; i < n; i++) distance[i][i] = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
		}
	}
}
