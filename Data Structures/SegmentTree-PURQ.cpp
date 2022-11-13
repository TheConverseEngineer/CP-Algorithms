/** Implementation of a simple segment tree that supports adition by default
  * To change the function, replace the following:
      - the plus sign on line 15
      - the plus sign on line 19
      - the += signs on lines 25 and 26
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
		for (int i{n}; i < 2*n; i++) segTree[i] = values[i-n];
  		for (int i{n - 1}; i > 0; i--) segTree[i] = segTree[i<<1] + segTree[i<<1|1];
	}
	void update(int pos, int value) { 
  		for (segTree[pos += n] = value; pos > 1; pos >>= 1) segTree[pos>>1] = segTree[pos] + segTree[pos^1];
	}
	int query(int l, int r) {
  		int ret = 0;
  		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    		if (l&1) ret += segTree[l++];
    		if (r&1) ret += segTree[--r];
  		}
  		return ret;
	}
};
