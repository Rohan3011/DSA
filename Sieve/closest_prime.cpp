#include<bits/stdc++.h>
using namespace std ;

vector<int> createSieve() {
	const int limit = 1000009;
	bool sieve[limit + 1] ;
	memset(sieve , true , sizeof(sieve));
	vector<int> primes ;
	for (int  i = 2 ; i * i <= limit ; i++) {
		if (sieve[i]) {
			for (int j = i * i ; j <= limit ; j += i)
				sieve[j] = false ;
		}
	}
	for (int i = 2 ; i <= limit ; i++) {
		if (sieve[i])
			primes.push_back(i) ;
	}
	return primes;
}

int lowerBound(int n , vector<int> primes) {
	int low = 0 , high = primes.size(), ans = 0 ;
	while (high >= low) {
		int mid = low + (high - low) / 2 ;
		if (primes[mid] <= n ) {
			ans = mid ;
			low = mid + 1 ;
		}
		else
			high = mid - 1;
	}
	if (ans + 1 < primes.size() && primes[ans + 1] - n < n - primes[ans])
		ans++;
	return primes[ans] ;
}
int main() {
	vector<int> primes =  createSieve() ;
	int n ;
	cin >> n ;
	cout << lowerBound(n , primes) << "\n" ;
}