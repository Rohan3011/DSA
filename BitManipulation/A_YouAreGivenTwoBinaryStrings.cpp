#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0) ; cin.tie(0);
	int t ;
	cin >> t ;
	while (t--) {
		string x , y ;
		cin >> x >> y ;
		int a , b , n = x.size() , m = y.size() ;
		for (int i = m - 1; i >= 0 ; i--) {
			if (y[i] == '1') {
				a = i ;
				break ;
			}
		}
		if (n > m) a += (n - m);
		for (int i = n - 1; i >= 0 ; i--) {
			if (x[i] == '1' && i <= a) {
				b = i ;
				break;
			}
		}
		if (m > n) b += (m - n);

		cout << abs(a - b) << "\n";
	}
}
