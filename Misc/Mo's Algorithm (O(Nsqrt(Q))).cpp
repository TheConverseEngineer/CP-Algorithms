

const int rotateDelta[4] = {3, 0, 0, 1};
inline ll findQueryOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) return 0;
	int hpow = 1<<(pow-1);
	int seg = (x<hpow)?((y < hpow)?0:3):((y<hpow)?1:2);
	seg = (seg + rotate) & 3;
	int nx = x&(x^hpow);
	int ny = y&(y^hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	ll subSquareSize = ll(1)<<(2*pow - 2);
	ll ans = seg * subSquareSize;
	ll add = findQueryOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 or seg == 2)?add:(subSquareSize - add - 1);
	return ans;
}

struct Query {
	int l, r, idx;
	ll ord;
	inline void setOrd() {
		ord = findQueryOrder(l, r, 20, 0);
	}
	bool operator<(const Query& other) {
		return ord < other.ord;
	}
};

vector<Query> queries;
vector<int> ans;

int main() {
  FOR(q, 0, Q) {
		int _l, _r; cin >> _l >> _r; _l--; _r--;
		queries[q] = {_l, _r, q, 0};
		queries[q].getOrd();
	}
	sort(all(queries));

	for(Query q : queries) {
		while (l > q.l) addLeft();
		while (r < q.r) addRight();
		while (l < q.l) removeLeft();
		while (r > q.r) removeRight();
		ans[q.idx] = maxStrokes;
	}
}
