#include <bits/stdc++.h>
using namespace std ;

int lowerBound(int arr[] , int n , int value) {
	int l = 0 , r = n - 1 , ans = 0 ;
	while (r >= l) {
		int mid = l + (r - l) / 2 ;
		if (arr[mid] <= value) {
			ans = mid ;
			l = mid + 1 ;
		}
		else
			r = mid - 1 ;
	}
	return ans ;
}

int main() {
	int n ;
	cin >> n ;
	int arr[n] , preffixsum[n];
	for (int i = 0 ; i < n ; i++) cin >> arr[i] ;
	sort(arr , arr + n) ;
	preffixsum[0] = arr[0] ;
	for (int i = 1 ; i < n ; i++)
		preffixsum[i] = arr[i] + preffixsum[i - 1];
	int q ;
	cin >> q ;
	while (q--) {
		int bishuPower ;
		cin >> bishuPower ;
		int ans = lowerBound(arr , n , bishuPower) ;
		cout << ans + 1 << " " <<  preffixsum[ans] << "\n";
	}
}