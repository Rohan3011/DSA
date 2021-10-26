#include <stdio.h>
#include <map>
int main() {
	int n , x ;
	scanf("%d" , &n);
	std::map<int, int> mp ;
	for (int i = 0 ; i < n ; i++) {
		scanf("%d" , &x);
		mp[x]++ ;
	}
	for (auto[x , y] : mp) {
		if (y == 1)
			printf("%d ", x);
	} puts("");
}