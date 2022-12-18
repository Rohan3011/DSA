#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int middle, int right) {
  vector<int> temp = arr;
  int i = left, j = middle, k = left;
  while (i <= middle - 1 && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  while (i <= middle - 1) {
    temp[k++] = arr[i++];
  }

  while (j <= right) {
    temp[k++] = arr[j++];
  }
  arr = temp;
}

void merge_sort(vector<int> &arr, int left, int right) {
  if (left >= right)
    return;
  int middle = (left + right) / 2;
  merge_sort(arr, left, middle);
  merge_sort(arr, middle + 1, right);
  merge(arr, left, middle + 1, right);
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &u : arr)
    cin >> u;
  merge_sort(arr, 0, n - 1);
  for (auto u : arr)
    cout << u << " ";
  cout << endl;
}