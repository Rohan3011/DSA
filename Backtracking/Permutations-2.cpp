#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ans;
    nextPermute(nums.size(), 0, nums, ans);
    return ans;
  }

  void nextPermute(int n, int idx, vector<int> &nums,
                   vector<vector<int>> &ans) {
    if (idx >= n) {
      ans.push_back(nums);
      return;
    }

    for (int i = idx; i < n; i++) {
      if (!canSwap(idx, i, nums))
        continue;
      swap(nums[i], nums[idx]);
      nextPermute(n, idx + 1, nums, ans);
      swap(nums[i], nums[idx]);
    }
  }

  bool canSwap(int idx, int curr, vector<int> &nums) {
    for (int i = idx; i < curr; i++) {
      if (nums[i] == nums[curr])
        return false;
    }
    return true;
  }

  void printPermutations(vector<vector<int>> &nums) {
    for (auto v : nums) {
      for (auto u : v)
        cout << u << " ";
      cout << "\n";
    }
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &u : arr)
    cin >> u;
  Solution sol;
  vector<vector<int>> ans = sol.permuteUnique(arr);
  sol.printPermutations(ans);
}