#include <bits/stdc++.h>
using namespace std ;

int main() {
	int t ;
	cin >> t ;
	while (t--) {
		string s;
		cin  >> s ;
		int starIndex = -3 ;
		bool ok = true ;
		for (int i = 0 ; i < s.size() ; i++) {
			if (s[i] == '0' && starIndex + 2 < i) {
				ok = false ;
			}
			else starIndex = i ;
		}
		puts(ok ? "YES" : "NO");
	}
}