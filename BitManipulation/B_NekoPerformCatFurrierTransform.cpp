#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0) ; cin.tie(0);
	int x , j = 19 , k ;
	cin >> x;
	cout << "39\n" ;
	while (j--) {
		k = log2(x) + 1 ;
		x ^= ((1 << k) - 1);
		x++ ;
		cout << k << ' ';
	}
	cout << log2(x) + 1 << '\n';
}
