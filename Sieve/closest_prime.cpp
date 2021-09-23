#include<iostream>
using namespace std ;

const int N = 1e7;
bool sieve[N + 1] = {true} ;
void createSieve() {
	// memset(sieve , true , sizeof(sieve));
	for (int i = 2 ; i * i <= N ; i++) {
		if (sieve[i]) {
			for (int j = i * i ; j <= N ; j += i)
				sieve[i] = false ;
		}
	}
}

int lowerBound(int n) {
	int low = 2 , high = N + 1 , ans = 0 ;
	while (high >= low) {
		int mid = low + (high - low) / 2 ;
		if (mid <= n) {
			ans = mid ;
			low = mid + 1 ;
		}
		else
			high = mid - 1;
	}
	return ans ;
}

int main() {
	createSieve() ;
	int n ;
	cin >> n ;
	cout << lowerBound(n) << "\n" ;
}