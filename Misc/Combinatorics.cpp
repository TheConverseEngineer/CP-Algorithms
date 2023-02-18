#define mod ((ll)(1e9 + 7))
ll factorial[1000005], inv[1000005];

ll pow(ll x, ll y) {
	ll res = 1; x %= mod;
	while (y) {
		if (y & 1) {
			res = (x*res)%mod; 
		}
		x = (x*x)%mod; 
		y >>= 1;
	}
	return res;
}

ll choose(ll n, ll r) {
	return factorial[n] * inv[r] % mod * inv[n - r] % mod;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	factorial[0] = 1;
	FOR(i, 1, 1000005) factorial[i] = (factorial[i-1] * i) % mod;
	inv[1000004] = pow(factorial[1000004], mod - 2);
	for (int i = 1000004; i > 0; i--) {
		inv[i-1] = (inv[i] * i) % mod;
	}

	cout << choose(15, 5);

}
