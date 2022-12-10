/* Simple Merge sort tree supporting two methods in log^2 N time
 * Total memory consumption NlogN
 * minGreater: smallest number greater than K, or MAX if this number does not exist
 * countGreater: number of numbers greater than K
 * NOTE: query ranges are inclusive-exclusive
 * the ub method is only needed for minGreater
*/
template <int n> struct MergeSortTree {
	vi s[2*n] = {};
	void buildFullTree() {
		for (int i = n-1; i > 0; i--) { 
			s[i].resize(sz(s[i<<1]) + sz(s[i<<1|1]));
			merge(all(s[i<<1]), all(s[i<<1|1]), s[i].begin());
		}
	}
	int ub(int node, int k, int MAX) {
		auto iter = upper_bound(all(s[node]), k);
		return (iter==s[node].end()) ? MAX:*iter;
	}
	int minGreater(int l, int r, int k, int MAX) { 
		int output = MAX;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l&1) output = min(output, ub(l++, k, MAX));
			if (r&1) output = min(output, ub(--r, k, MAX));
		}
		return output;
	}
	int countGreater(int l, int r, int k) { // returns smallest number greater than K, or MAX if this number does not exist
		int output = 0;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l&1) output += s[l].end() - upper_bound(all(s[l]), k), l++;
			if (r&1) --r, output += s[r].end() - upper_bound(all(s[r]), k);
		}
		return output;
	}
};
