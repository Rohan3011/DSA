#include <stdio.h>
#include<algorithm>
using namespace std ;

int main() {
	int n , p ;
	scanf("%d %d", &n , &p);
	int streets[p + 2] = {0} ;
	for (int i = 0 ; i < n ; i++) {
		int x , r ;
		scanf("%d %d" , &x , &r) ;
		streets[max(0 , x - r)]++;
		streets[min(p , x + r) + 1]--;
	}
	for (int i = 1; i <= p ; i++)
		streets[i] += streets[i - 1] ;
	int ans = 0 , cnt = 0 ;
	for (int i = 0 ; i <= p ; i++) {
		if (streets[i] != 1)
			cnt++;
		else {
			ans = max(ans , cnt) ;
			cnt = 0 ;
		}
	}
	ans = max(ans , cnt) ;
	printf("%d\n", ans );
}