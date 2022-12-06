/** Simple fenwick tree. Supports addition by default, 
 * and can be swapped for other associative operations (requires inverse for non-prefix queries)
 * NOTE: one-indexed by default
 * int can be easily substituted for other types by changing line 7
 * queries of type [l, r]
 * */
template <int n> struct FenwickTree {
    int BIT[n+1] = {};  // binary indexed tree
    int query(int r) {
    	int ret{0};
        for (r++; r > 0; r -= r & -r) ret += BIT[r];
        return ret;
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
    void increment(int pos, int delta) {
        for (pos++; pos < n+1; pos += pos & -pos) BIT[pos] += delta;
    }
};
