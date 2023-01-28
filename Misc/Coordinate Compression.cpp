// Rather informal, just a snippet of my solution to Load Balancing

int N;
vector<pii> cows;
int main() {
	cin >> N;
	cows.resize(N);
	FOR(i, 0, N) cin >> cows[i].first >> cows[i].second;
	sort(all(cows));
	int current = -1, last = -1;
	FOR(i, 0, N) { 
		if (cows[i].first == last) cows[i].first = current;
		else {
			last = cows[i].first;
			cows[i].first = ++current;
		}
	}
	sort(all(cows), [](auto &a, auto &b) { return a.second < b.second; });
	current = -1, last = -1;
	FOR(i, 0, N) {
		if (cows[i].second == last) cows[i].second = current;
		else {
			last = cows[i].second;
			cows[i].second = ++current;
		}
	}
}
