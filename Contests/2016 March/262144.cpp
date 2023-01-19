#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((ll)(x))*(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Solves all test cases except for the last one

int dp[262145][55];
int a[262145];
int N;
int mx = 0;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("262144.in", "r", stdin);
	freopen("262144.out", "w", stdout);

	cin >> N;
	FOR(i, 0, N) cin >> a[i];

	FOR(n, 0, N) {
		FOR(k, 1, 55) {
			if (k < a[n]) dp[n][k] = -1;
			else if (k == a[n]){
				dp[n][k] = n;
				mx = max(mx, k);
			} else {
				if (dp[n][k-1]-1 < 0) dp[n][k] = -1;
				else {
					dp[n][k] = dp[dp[n][k-1]-1][k-1];
					if (dp[n][k] != -1) mx = max(mx, k);
				}
			}
		}
	}

	cout << mx;
}
