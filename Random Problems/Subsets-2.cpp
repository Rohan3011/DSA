#include "bits/stdc++.h"
using namespace std ;

// vector<vector<int>> ans ;

set<vector<int>> ans ;
void generateSubsets(vector<int> arr , int i , vector<int> curr) {
	if (i >= arr.size() ) {
		ans.insert(curr);
		return ;
	}
	generateSubsets(arr , i + 1 , curr) ;
	curr.push_back(arr[i]);
	generateSubsets(arr , i + 1 , curr);

}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<int> curr ;
	generateSubsets(nums, 0 , curr);
	vector<vector<int>> v ;
	for (auto u : ans) {
		vector<int> temp ;
		for (auto x : u) {
			temp.push_back(x) ;
		}
		v.push_back(temp);
	}
	return v ;
}
int main() {
	int n ;
	cin >> n ;
	vector<int> arr(n) ;
	for (auto &i : arr) cin >> i ;
	vector<vector<int>> ans = subsetsWithDup(arr);
	for (auto u : ans) {
		for (auto x : u ) cout << x << " ";
		cout << "\n" ;
	}
}
