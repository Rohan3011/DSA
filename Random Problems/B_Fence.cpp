#include "iostream"
using namespace std ;

int main() {
	ios::sync_with_stdio(0) ; cin.tie(0);
	int n , k ;
	cin >> n >> k ;
	int arr[n] ;
	for (auto &i : arr) cin >> i ;
	int window = 0 ;
	for (int i = 0 ; i < k ; i++)
		window += arr[i] ;
	int ans = window , idx = 0 ;
	for (int i = 0 ; i + k < n ; i++) {
		window = window -  arr[i] + arr[i + k] ;
		if (ans > window)
			ans = window , idx = i + 1;
	}
	cout << idx + 1 << "\n" ;
}