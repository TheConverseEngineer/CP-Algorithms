/** Simple fenwick tree. Supports addition by default, 
	 * and can be swapped for other simple operations
 * */
struct FenwickTree {
	vector<int> BIT;  // binary indexed tree
    int n;
    FenwickTree(int _n) {
        n = _n+1;
        BIT.assign(_n+1, 0);
    }
    int query(int r) {
    	int ret{0};
        for (r++; r > 0; r -= r & -r) ret += BIT[r];
        return ret;
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
    void increment(int pos, int delta) {
        for (pos++; pos < n; pos += pos & -pos) BIT[pos] += delta;
    }
};
