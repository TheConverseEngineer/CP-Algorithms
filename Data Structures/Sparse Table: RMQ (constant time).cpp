#define MAX_H 18
#define MAX_N 100000
int sparseTable[MAX_H][MAX_N];

/** Builder method for RMQ Sparse Table. Handles min queries in O(1) time after O(N*logN) 
 *  processing. Note that it uses globally defined integer array sparseTable
 *  The dimensions of the array should be (ceil(logN) + 1, N). The first dimension can be
 *  safely overestimated. It is assumed that the base values (0<=i<N) are stored in 
 * 	sparseTable[0][i]
 *  
 *  @param n 	total number of elements
 *  @param k    ceil(log n), do not add one
 */
void build_sparse_table(int n, int k) {
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j + (1<<i) <= n; ++j) {
			sparseTable[i][j] = min(sparseTable[i-1][j], sparseTable[i-1][j + (1<<(i-1))]);
		}
	}
}

/** Compute minimum on specified range. Range is inclusive */ 
int query_min(int l, int r) {
	int i = __builtin_clz(1) - __builtin_clz(r-l+1);
	return min(sparseTable[i][l], sparseTable[i][r - (1<<i) + 1]);
}
