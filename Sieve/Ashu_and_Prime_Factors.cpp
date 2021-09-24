#include<bits/stdc++.h>
using namespace std ;

const int N = 1e6;
vector<int>sieve(N + 1 , 1) ;
void createSieve() {
	for (int i = 2 ; i * i <= N ; i++) {
		if (sieve[i]) {
			for (int j = i * i ; j <= N ; j += i) {
				if (sieve[j]) {
					sieve[j] = 0;
					sieve[i]++;
				}
			}
		}
	}

}


int main() {
	ios::sync_with_stdio(0) ; cin.tie(0) ;
	createSieve();
	int t ;
	cin >> t ;
	while (t--) {
		int n ;
		cin >> n ;
		cout << sieve[n] << "\n" ;
	}
}