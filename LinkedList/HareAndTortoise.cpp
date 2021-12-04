#include "bits/stdc++.h"
#include "LinkedList.cpp"
using namespace std ;

int middle(Node* head) {
	Node *slow = head , *fast = head ;
	while (fast && fast->next) {
		slow = slow->next ;
		fast = fast->next->next ;
	}
	return slow->data;
}

int main() {
	LinkedList list ;
	int n ;
	cin >> n ;
	vector<int> values(n);
	for (auto &v : values) cin >> v ;
	list.construct(values);
	cout << middle(list.head) << '\n';
}