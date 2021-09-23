#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

vector<bool> segmentedSieve(ll L , ll R) {
	// generating all primes till sqrt(R)
	ll limit = sqrt(R) ;
	vector<bool>sieve(limit + 1 , true) ;
	vector<ll> primes ;
	for (ll i = 2 ; i <= limit ; i++) {
		if (sieve[i]) {
			primes.push_back(i) ;
			for (ll j = i * i ; j <= limit ; j += i)
				sieve[j] = false ;
		}
	}
	// primes in range[L,R]
	vector<bool> isPrime(R - L + 1 , true);
	for (auto u : primes) {
		ll firstMultiple = (L / u) * u ;
		if (firstMultiple < L) firstMultiple += u ;
		for (ll i = max(firstMultiple , u * u ) ; i <= R ; i += u)
			isPrime[i - L] = false ;
	}
	if (L == 1)
		isPrime[0] = false ;
	return isPrime ;
}

int main() {
	int t ;
	cin >> t ;
	while (t--) {
		ll m , n ;
		cin >> m >> n ;
		vector<bool> isPrime = segmentedSieve(m , n) ;
		for (ll i = m ; i <= n ; i++) {
			if (isPrime[i - m])
				cout << i << "\n" ;
		}
	}
}