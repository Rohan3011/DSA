#include <bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n) {
  vector<long long> ans(n, -1);
  stack<long long> st;
  for (int i = 0; i < n; i++) {
    if (st.empty()) {
      st.push(i);
      continue;
    }
    while (!st.empty() && arr[st.top()] < arr[i]) {
      ans[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<long long> arr(n);
  for (auto &i : arr) cin >> i;
  vector<long long> ans = nextLargerElement(arr, n);
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}
