#include <bits/stdc++.h>
using namespace std ;

bool isStable(char open , char close) {
	return (open == '{' && close == '}');
}

int cost(stack<char> &bracket) {
	int open = 0 , close = 0 ;
	while (!bracket.empty()) {
		if (bracket.top() == '{')
			open++;
		else
			close++;
		bracket.pop();
	}
	int ans = (open + close) / 2;
	if ((open & 1) && (close & 1)) ans++;
	return ans;
}

void stable_string(string s , int index) {
	stack<char> bracket ;
	for (auto &u : s) {
		if (bracket.empty())
			bracket.push(u);
		else if (isStable(bracket.top() , u))
			bracket.pop();
		else
			bracket.push(u);
	}

	cout << index << ". " <<  cost(bracket) << '\n';
}


int main() {
	int index = 0;
	string s ;
	while (cin >> s) {
		if (s[0] == '-')
			return 0 ;
		stable_string(s , ++index);
	}
}