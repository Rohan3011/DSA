#include <bits/stdc++.h>
using namespace std ;

void sliding_window(int arr[] , int n , int a , int b) ;

int main() {
	ios::sync_with_stdio(0) ; cin.tie(0) ;
	int t = 0 ;
	cin >> t ;
	while (t--) {
		int n = 0, b = 0 , a = 0 ;
		cin >> n >> b >> a ;
		int arr[n] ;
		for (auto &i : arr) cin >> i ;
		sliding_window(arr , n , a , b) ;
	}
}

void sliding_window(int arr[] , int n , int a , int b) {
	long double ans = 0.0 ;
	for (int k = a ; k <= b ; k++) {
		long double sum = 0.0 ;
		for (int i = 0 ; i < k ; i++)
			sum += arr[i] ;
		ans = max(ans , sum / k);
		for (int i = k ; i < n ; i++) {
			sum = sum + arr[i] - arr[i - k] ;
			ans = max(ans , sum / k) ;
		}
	}
	cout << fixed << setprecision(9) << ans << "\n" ;
}
