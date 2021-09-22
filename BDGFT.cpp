#include <iostream>
using namespace std ;

int main() {
	int t ;
	cin >> t ;
	while (t--) {
		string s ;
		cin >> s ;
		int n = s.size() , ans = 0  ;
		int one[n + 1] ;
		one[0] = 0 ;
		for (int i = 1 ; i <= n ; i++)
			one[i] = one[i - 1] + s[i - 1] - '0' ;
		for (int i = 0 ; i < n ; i++) {
			int x = 1 ; // count of ones
			while (true) {
				int j = i + x * x + x ; // required length of substring for x ones
				if (j > n) break ;
				int cnt = one[j] - one[i] ;
				if (cnt == x) ans++ ;
				x++;
			}
		}
		cout << ans << "\n" ;
	}
}