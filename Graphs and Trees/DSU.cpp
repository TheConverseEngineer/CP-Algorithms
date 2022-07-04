/** Simple DSU, heavily inspired by BenQ's implementation */
struct DSU {
	vector<int> size;
	DSU(int _n) { size.assign(_n, -1); }
	int getRep(int a) { return size[a] < 0 ? a : size[a] = getRep(size[a]); }
	bool connected(int a, int b) { return getRep(a) == getRep(b); }
	int compSize(int a) { return -size[getRep(a)]; }
	bool connect(int a, int b) {  // union by size
		a = getRep(a); b = getRep(b);
		if (a == b) return false;
		if (size[a] > size[b]) swap(a, b);
		size[a] += size[b];
    size[b] = a;
		return true;
	}
};
