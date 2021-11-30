#include "bits/stdc++.h"
using namespace std ;


string isBalanced(string s) {
	map<char, char> bracket = {{'(', ')'} , {'{' , '}'} , {'['  , ']'}};
	stack<char> open ;
	for (auto &b : s) {
		if (bracket.find(b) != bracket.end())
			open.push(b) ;
		else {
			if (open.empty() || bracket[open.top()] != b)
				return "NO" ;
			else
				open.pop() ;
		}
	}
	return (open.empty() ? "YES" : "NO");
}

int main() {
	int n ;
	cin >> n ;
	string s;
	for (int i = 0 ; i < n ; i++) {
		cin >> s ;
		cout << isBalanced(s) << '\n';
	}

}