#include<bits/stdc++.h>
using namespace std ;

int const limit = 1e7 + 1 ;
vector<int> prime(limit, 0) ;
void createSieve();
void freqPrimeFactor(int arr[], int n , vector<int>&freq);
void delcomfreq(int arr[] , int n , vector<int>& freq );

int main() {
	ios::sync_with_stdio(0) ; cin.tie(0);
	createSieve() ;
	int n , m ;
	cin >> n >> m ;
	int A[n] , B[m] ;
	for (auto &i : A) cin >> i ;
	for (auto &i : B) cin >> i ;
	// frequency of a primeFactor
	vector<int> freqPrimeFactor_A(limit , 0) ;
	vector<int> freqPrimeFactor_B(limit , 0) ;

	freqPrimeFactor(A , n , freqPrimeFactor_A );
	freqPrimeFactor(B , m , freqPrimeFactor_B );

	delcomfreq(A , n , freqPrimeFactor_B ) ;
	delcomfreq(B , m , freqPrimeFactor_A ) ;
	cout << n << " " << m << "\n" ;
	for (auto u : A) cout << u << " " ;
	cout << "\n" ;
	for (auto u : B) cout << u << " " ;
	cout << "\n" ;

}

void createSieve() {
	for (int i = 2 ; i * i < limit; i++) {
		if (!prime[i]) {
			for (int j = i * i ; j < limit ; j += i)
				prime[j] = i ;
		}
	}
	for (int i = 0 ; i < limit ; i++) {
		if (!prime[i])
			prime[i] = i ;
	}

}

void freqPrimeFactor(int arr[], int n , vector<int>&freq) {
	for (int i = 0 ; i < n ; i++) {
		for (int j = arr[i] ; j > 1 ; j /= prime[j] ) {
			freq[prime[j]]++ ;
		}
	}
}
// Delete common prime factors
void delcomfreq(int arr[] , int n , vector<int>& freq ) {
	for (int i = 0 ; i < n ; i++) {
		for (int j = arr[i] ; j > 1 ; j /= prime[j] ) {
			if (freq[prime[j]]) {
				freq[prime[j]]-- ;
				arr[i] /= prime[j] ;
			}

		}
	}
}