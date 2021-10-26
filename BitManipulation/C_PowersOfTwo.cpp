#include <bits/stdc++.h>
using namespace std ;
int main() {
	int n , k ;
	scanf("%d %d", &n , &k);
	vector<int> ans(k , 1) ;
	n -= k ;
	for (int i = 0 ; n && i < k ; i++) {
		while (ans[i] <= n) {
			n -= ans[i];
			ans[i] *= 2;
		}
	}
	if (n) puts("NO") ;
	else {
		puts("YES") ;
		for (auto u : ans) printf("%d ", u);
		puts("");
	}

}
