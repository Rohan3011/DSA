#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
typedef long long ll ;

ll totalCost(ll arr[] , ll n , ll k) {
	ll cost = 0 , price[n] ;
	for (ll i = 0 ; i < n  ; i++)
		price[i] = arr[i] + (i + 1) * k;
	sort(price , price + n) ;
	for (ll i = 0 ; i < k  ; i++) cost += price[i] ;
	return cost ;
}

vector<ll> binarySearch(ll arr[] , ll n , ll sum) {
	vector<ll> ans(2 , 0) ;
	ll l = 0 , r = n ;
	while (r >= l) {
		ll mid = l + (r - l) / 2 ;
		ll cost = totalCost(arr , n , mid) ;
		if (cost <= sum) {
			if (mid >= ans[0]) {
				ans[0] = mid ;
				ans[1] = cost ;
			}
			l = mid + 1 ;
		}
		else
			r = mid - 1;
	}
	return ans ;
}

int  main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n , sum ;
	cin >> n >> sum ;
	ll arr[n] ;
	for (auto &i : arr) cin >> i ;
	vector<ll> ans = binarySearch(arr , n , sum) ;
	cout << ans[0] << " " << ans[1] <<  "\n";
}