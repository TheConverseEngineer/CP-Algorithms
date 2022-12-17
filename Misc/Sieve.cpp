// Implementation of Sieve of Erastothenes
// Finds all primes up to N in O(Nlog(logN)) (very quickly) 
memset(prime, true, sizeof(prime));
for (int p = 2; p * p <= 5000005; p++) {
    if (prime[p] == true) {
        for (int i = p * p; i < 5000005; i += p) prime[i] = false;
    }
}
