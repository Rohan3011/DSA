
#include <algorithm>
#include <iostream>
using namespace std;

// O(N logN) solution
int binarySearch(int arr[], int n, int c) {
  int l = 0, r = arr[n - 1] - arr[0], ans = 0;
  while (l <= r) {
    int mid = l + (r - l) / 2, placed = 1, prev = 0;
    for (int i = 0; i < n; i++) {
      if (arr[prev] + mid <= arr[i]) {
        prev = i;
        placed++;
      }
    }
    if (placed >= c) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;
    int stalls[n];
    for (auto &i : stalls)
      cin >> i;
    sort(stalls, stalls + n);
    cout << binarySearch(stalls, n, c) << "\n";
  }
}
