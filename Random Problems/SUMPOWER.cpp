#include <iostream>
using namespace std ;

int main() {
	ios::sync_with_stdio(0) ; cin.tie(0);
	int t ;
	cin >> t ;
	while (t--) {
		int n , k ;
		long long  ans = 0 ;
		string s ;
		cin >> n >> k >> s;
		int diff[n] = {0};
		for (int i = 1 ; i < n ; i++)
			diff[i] = (s[i] != s[i - 1]) ;
		for (int i = 1 ; i < n ; i++)
			diff[i] += diff[i - 1];
		for (int i = 0 ; i + k < n ; i++)
			ans += diff[i + k] - diff[i] ;
		cout << ans << "\n";
	}
}