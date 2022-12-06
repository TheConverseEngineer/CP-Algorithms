/** Implementation of a simple segment tree that supports addition by default
  * The combiner function can be replaced with any associative operation.
  * If using a function like max, make sure that line 16's defaults are updated as needed.
  * NOTE: query range is inclusive-exclusive: ie. [l, r)
*/
template <class T, int n> struct SegmentTree {
	T comb(T a, T b) { return a+b; }
	T s[2*n] = {};
	void buildFullTree() {
		for (int i = n-1; i > 0; i--) s[i] = comb(s[i<<1], s[i<<1|1]);
	}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;) s[pos] = comb(s[pos<<1], s[pos<<1|1]);
	}
	T query(int l, int r) { // query [ b , e)
		T resL = 0, resR = 0;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l&1) resL = comb(resL, s[l++]);
			if (r&1) resR = comb(s[--r], resR);
		}
		return comb(resL, resR);
	}
};
