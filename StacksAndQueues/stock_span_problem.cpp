#include<bits/stdc++.h>
using namespace std ;

vector <int> calculateSpan(int price[], int n) {
	vector<int> ans (n , 1) ;
	stack<int> st ;
	for (int i = 0 ; i < n ; i++) {
		if (st.empty())
			st.push(i) ;
		else {
			int prev = 0 ;
			while (!st.empty() && price[st.top()] <= price[i]) {
				prev += ans[st.top()] ;
				st.pop() ;
			}
			st.push(i);
			ans[i] += prev ;
		}
	}
	return ans ;
}
int main() {
	int n ;
	cin >> n ;
	int price[n] ;
	for (auto &i : price) cin >> i ;
	vector<int> ans = calculateSpan(price , n) ;
	for (auto u : ans) cout << u << " ";
	cout << "\n" ;
}