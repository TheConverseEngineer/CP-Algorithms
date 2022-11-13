/** Implementation of a simple segment tree (Range Update, Point Query) that supports addition by default
  * To change the function, replace the following:
      - the plus sign on line 21
      - the increment signs on lines 24, 28, 29, 35, and 36
      	- if doing a non-commutative op, line 26 should be ret = segTree[--r] OP ret
  * NOTE: query range is inclusive-exclusive: ie. [a, b)
*/
struct SegmentTree {
	int n; 
	vector<int> segTree;
	SegmentTree(int _n) {
		n = _n;
		segTree.assign(2*n, 0);
	}
	SegmentTree(const vector<int>& values) {
		n = values.size();
		segTree.assign(2*n, 0);
		segTree[n] = values[0];
		for (int i{n+1}; i < 2*n; i++) segTree[i] = values[i-n] - values[i-n-1];
  	for (int i{n - 1}; i > 0; i--) segTree[i] = segTree[i<<1] + segTree[i<<1|1];
	}
	void increment(int l, int r, int inc) { 
		if (r > n) {
			for (l += n; l > 0; l >>= 1) segTree[l] += inc;
			return;
		}
  	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
  		segTree[l] += inc;
    	segTree[r] -= inc;
  	}
	}
	int query(int p) {
  	int ret = 0, l = n;
  	for (p += n + 1; l < p; l >>= 1, p >>= 1) {
    	if (l&1) ret += segTree[l++];
    	if (p&1) ret += segTree[--p];
  	}
  	return ret;
	}
};
