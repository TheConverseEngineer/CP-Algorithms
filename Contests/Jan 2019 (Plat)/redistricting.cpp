using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define FOR(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((ll)(x))*(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <class T> bool ckmax(T&a, const T& b) { return a < b ? a = b, 1 : 0;}


#define MAXN 300001
int N, K;

int gCount[MAXN], dp[MAXN];

bool won(int a, int b) {
	return 2*(gCount[b]-gCount[a-1]) >= (b-a+1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("redistricting.in", "r", stdin);
	freopen("redistricting.out", "w", stdout);
	
	cin >> N >> K;
	FOR(i, 0, N) {
		char a; cin >> a;
		gCount[i+1] = gCount[i] + (a=='G');
	}

	for(int i = 1; i <= N; i++) {
		dp[i] = dp[i-1] + won(i, i);
		for (int last = 1; last <= i and last <= K; last++) {
			dp[i] = min(dp[i], dp[i-last] + won(i-last+1, i));
		}
	}
	cout << dp[N];
}
