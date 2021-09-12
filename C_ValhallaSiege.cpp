#include "iostream"
using namespace std ;
typedef long long ll ;

int upperBound(ll arr[] , ll n , ll value) {
	ll l = 0 , r = n - 1 , ans = n - 1 ;
	while (l <= r) {
		ll mid =  l + (r - l) / 2 ;
		if (value < arr[mid]) {
			ans = mid ;
			r = mid - 1 ;
		}
		else
			l = mid + 1;
	}
	return  ans;
}

int main() {
	ll n , q ;
	cin >> n >> q ;
	ll warriors[n] , arrows[q] , prefixsum[n] ;
	for (auto &i : warriors) cin >> i ;
	prefixsum[0] = warriors[0] ;
	for (int i = 1 ; i < n ; i++)
		prefixsum[i] = warriors[i] + prefixsum[i - 1] ;
	ll damage = 0 ;
	for (auto &i : arrows) {
		cin >> i ;
		ll ans =  upperBound(prefixsum , n , i + damage);
		if (prefixsum[ans] <= i + damage ) {
			damage = 0 ;
			cout << n << "\n" ;
		}
		else {
			damage += i ;
			cout << n -  ans << "\n" ;
		}
	}
}