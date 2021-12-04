#include <bits/stdc++.h>
#include "LinkedList.cpp"

void mergeList(Node* h1 , Node* h2) {
	LinkedList sortedList ;
	while (h1 && h2) {
		if (h1->data > h2->data) {
			sortedList.insert(h2->data);
			h2 = h2->next ;
		}
		else {
			sortedList.insert(h1->data);
			h1 = h1->next;
		}
	}

	while (h1) {
		sortedList.insert(h1->data);
		h1 = h1->next ;
	}
	while (h2) {
		sortedList.insert(h2->data);
		h2 = h2->next ;
	}
	sortedList.print() ;
}



int main() {
	LinkedList list1 , list2 ;
	int n , m ;
	cin >> n >> m ;
	vector<int> values1(n) , values2(m);
	for (auto &v : values1) cin >> v ;
	for (auto &v : values2) cin >> v ;
	list1.construct(values1);
	list2.construct(values2);
	mergeList(list1.head , list2.head) ;
}
