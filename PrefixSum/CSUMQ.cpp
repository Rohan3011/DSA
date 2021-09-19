#include<iostream>
using namespace std ;
typedef long long ll ;

int main() {
	int n , q ;
	cin >> n ;
	ll arr[n] , prefix[n];
	for (auto &i : arr) cin >> i ;
	prefix[0] = arr[0] ;
	for (int i = 1 ; i < n ; i++)
		prefix[i] = prefix[i - 1] + arr[i] ;

	cin >> q ;
	while (q--) {
		int l , r ;
		cin >> l >> r ;
		cout << prefix[r] - (l > 0 ? prefix[l - 1] : 0) << "\n" ;
	}
}