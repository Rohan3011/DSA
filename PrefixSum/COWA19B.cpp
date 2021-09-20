#include<stdio.h>

int main() {
	int n , q , m ;
	scanf("%d %d" , &n , &q) ;
	long long arr1[n + 1] = {0} , arr2[n + 1] = {0} ;
	while (q--) {
		int l , r ;
		scanf("%d %d", &l , &r) ;
		arr1[l] += 1 ;
		if (r + 1 <= n ) {
			arr1[r + 1] -= 1;
			arr2[r + 1] -= (r - l + 1) ;
		}
	}
	// Take Prefix sum twice , so to eliminate extra we use second array
	for (int i = 1 ; i <= n ; i++)
		arr1[i] += arr1[i - 1] ;
	for (int i = 1 ; i <= n ; i++)
		arr2[i] += arr2[i - 1] + arr1[i] ;

	scanf("%d" , &m) ;
	while (m--) {
		int idx ;
		scanf("%d" , &idx) ;
		printf("%lld\n" , arr2[idx]) ;
	}
}
