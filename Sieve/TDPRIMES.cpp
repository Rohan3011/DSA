#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int N = 1e8 + 1 ;
bool sieve[N + 1] ;
void createSieve() {
	memset(sieve , true , sizeof(sieve));
	for (ll i = 2 ; i * i <= N ; i++) {
		if (sieve[i]) {
			for (ll j = i * i ; j <= N ; j += i)
				sieve[j] = false ;
		}
	}
}

int main() {
	createSieve() ;
	ll cnt = 0 ;
	for (ll i = 2 ; i <= N ; i++) {
		if (sieve[i]) {
			cnt++ ;
			if (cnt % 100 == 1)
				cout << i << "\n";
		}
	}
}