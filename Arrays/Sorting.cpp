#include<bits/stdc++.h>
using namespace std;


void bubbleSort(vector<int> &arr) {
	int n = arr.size() ;
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n - i - 1 ; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j] , arr[j + 1]);
		}
	}
}

void merge(vector<int> &arr , int start, int middle , int end) {
	vector<int> temp;
	int left = start , right = middle + 1 ;
	while (left <= middle && right <= end) {
		if (arr[left] < arr[right])
			temp.push_back(arr[left++]);
		else
			temp.push_back(arr[right++]);
	}
	while (left <= middle) {
		temp.push_back(arr[left++]);
	}
	while (right <= end) {
		temp.push_back(arr[right++]);
	}
	for (int i = start , k = 0 ; i <= end ; i++ , k++)
		arr[i] = temp[k] ;
}

void mergeSort(vector<int> &arr , int start , int end) {
	if (start >= end) {
		return;
	}
	int middle = (start + end) / 2 ;
	mergeSort(arr , start , middle);
	mergeSort(arr , middle + 1 , end);
	merge(arr , start, middle  , end) ;
}


int main()
{
	//ios::sync_with_stdio(0);cin.tie(0);
	int n ;
	cin >> n;
	vector<int> arr(n) ;
	for (int &u : arr) cin >> u ;
	// bubbleSort(arr) ;
	mergeSort(arr , 0 , n - 1) ;
	for (auto &u : arr)
		cout << u << " ";
	cout << "\n";

}