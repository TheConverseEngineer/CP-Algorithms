
// Given two arrays, A[mask] and F[mask], the following function sets F[S] = sum over A[V] for all subsets V of S
// Runs is O(2^N)

void sos() {
	FOR(i, 0, (1<<N)) F[i] = A[i];
	FOR(i, 0, N) { 
		FOR(mask, 0, (1<<N))
			if(mask & (1<<i)) F[mask] += F[mask^(1<<i)];
	}
}
