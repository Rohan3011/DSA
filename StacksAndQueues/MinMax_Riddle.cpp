#include <bits/stdc++.h>
using namespace std;

/*
Idea is that for each element find the window length(size) in which
that element is minimum.
Idea is same for both methods just implementation is different.
method 2 has smaller implementation but is difficult to understand(maybe).
*/
// Method 1 :
/*
vector<int> nextSmaller(vector<int> arr , int n) ;
vector<int> prevSmaller(vector<int> arr , int n) ;

int main() {
	int n ;
	cin >> n ;
	vector<int> arr(n) , left , right , ans(n + 1) ;
	for (auto &i : arr) cin >> i ;
	right = nextSmaller(arr , n) ;
	left = prevSmaller(arr , n ) ;

	// To Find maximum MinMax for lengths of window
	for (int i = 0 ; i < n ; i++) {
		int len = right[i] - left[i] - 1 ;
		ans[len] = max(ans[len] , arr[i]) ;
	}
	// To fill i where ans[i] = 0
	for (int i = n - 1 ; i >= 1 ; i--)
		ans[i] = max(ans[i] , ans[i + 1]);
	for (int i = 1; i <= n ; i++)
		cout << ans[i] << " " ;
	cout << "\n" ;
}


vector<int> nextSmaller(vector<int> arr , int n ) {
	vector<int> ans (n , n) ;
	stack<int> st ;
	st.push(0) ;
	for (int i = 1 ; i < n ; i++) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			ans[st.top()] = i ;
			st.pop() ;
		}
		st.push(i);
	}
	return ans ;
}

vector<int> prevSmaller(vector<int> arr , int n) {
	vector<int> ans(n , -1) ;
	stack<int> st ;
	st.push(n - 1) ;
	for (int i = n - 2 ; i >= 0 ; i--) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			ans[st.top()] = i ;
			st.pop() ;
		}
		st.push(i) ;
	}
	return ans ;
}
*/

// Method 2 :
vector<int> riddle(vector<int> arr) {
	arr.push_back(-1) ;
	int n = arr.size() , i = 0 ;
	vector<int> ans(n - 1) ;
	stack<int> st ;
	while (i < n) {
		if (st.empty() || arr[st.top()] < arr[i])
			st.push(i++);
		else {
			int value = arr[st.top()];
			st.pop();
			int len = (st.empty() ? i : i - st.top() - 1) ;
			ans[len - 1] = max(value , ans[len - 1]) ;
		}
	}

	for (int i = ans.size() - 2 ; i >= 0 ; i--)
		ans[i] = max(ans[i] , ans[i + 1]) ;
	return ans ;
}



int main() {
	int n ;
	cin >> n ;
	vector<int> arr(n) , ans ;
	for (auto &i : arr) cin >> i ;
	ans = riddle(arr) ;
	for (auto u : ans) cout << u << " " ;
	cout << "\n" ;
}