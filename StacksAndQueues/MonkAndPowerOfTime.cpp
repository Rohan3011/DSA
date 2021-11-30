#include <bits/stdc++.h>
using namespace std ;

int main() {
	int n , x ;
	cin >> n ;
	queue<int> q1 , q2 ;
	for (int i = 0 ; i < n ; i++) {
		cin >> x ;
		q1.push(x);
	}
	for (int i = 0 ; i < n ; i++) {
		cin >> x ;
		q2.push(x);
	}
	int cost = 0 ;
	while (!q2.empty()) {
		while (q2.front() != q1.front()) {
			int temp = q1.front();
			q1.pop();
			q1.push(temp);
			cost++;
		}
		cost++;
		q2.pop();
		q1.pop();
	}
	cout << cost << '\n';
}