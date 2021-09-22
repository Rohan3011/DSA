#include <iostream>
using namespace std ;

int main() {
	ios::sync_with_stdio(0) ; cin.tie(0);
	int t ;
	cin >> t ;
	while (t--) {
		int n , k , left = 1  , ans = 0  ;
		cin >> n >> k ;
		int arr[n + 1] , peek[n + 1] = {0} , prefix[n + 1 ] = {0} ;
		for (int i = 1 ; i <= n ; i++)
			cin >> arr[i] ;
		for (int i = 2 ; i <= n - 1; i++) {
			if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
				peek[i] = 1 ;
		}
		for (int i = 1 ; i <= n ; i++)
			prefix[i] = peek[i] + prefix[i - 1] ;
		for (int i = 1;  i <= n - k + 1 ; i++ ) {
			/*	exclude the boundaries (first and last index) of segment
				 because a peek cannot exist with single neighbour */
			int temp = prefix[i + k - 2] - prefix[i] ;
			if (temp > ans) {
				ans = temp ;
				left =  i ;
			}
		}
		cout << ans + 1 << " " << left << "\n" ;
	}
}
