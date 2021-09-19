#include <bits/stdc++.h>
using namespace std ;

int main() {
	ios::sync_with_stdio(0) ; cin.tie(0) ;
	int t ;
	cin >> t  ;
	while (t--) {
		int n ;
		cin >> n ;
		int arr[n] ;
		long long shot = 0ll ;
		for (auto &i : arr) cin >> i ;
		for (int i = 0 ; i < n ; i++) {
			if  (arr[i] == -1)
				arr[i] = shot / max(1 , i) ;
			shot += arr[i] ;
		}
		for (auto u : arr) cout << u << " " ;
		cout << "\n" ;
	}
}