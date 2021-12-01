#include <iostream>
#include <vector>
using namespace std ;

class Node
{
public:
	Node(int data) {
		this->data = data ;
		this->next = NULL ;
	}
	Node *next ;
	int data ;
};

class LinkedList
{
	Node *head ;
public:
	LinkedList() {
		head = NULL;
	};
	void constructList(vector<int>);
	void insertNode(int);
	void deleteNode(int);
	void printList();
	void reverseList();
};

// constructs the linked list with given values
void LinkedList::constructList(vector<int> values) {
	for (auto &u : values)
		this->insertNode(u);
}



// Insert's the element at the end (tail)
void LinkedList::insertNode(int data) {
	Node* newNode = new Node(data);

	if (head == NULL) {
		head = newNode ;
		return;
	}
	Node* temp = head ;
	while (temp->next) {
		temp = temp->next ;
	}
	temp->next = newNode;
}

// prints the Linked List
void LinkedList::printList() {
	Node* temp = head;
	while (temp) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL\n";
}

// delete's the node with given index (zero based)
void LinkedList::deleteNode(int nodeIndex) {
	Node* temp = head;
	if (!nodeIndex) {
		Node* newHead = head->next ;
		delete head ;
		head = newHead ;
		return;
	}
	int index = 0 ;
	while (index + 1 < nodeIndex && temp->next) {
		temp = temp->next;
		index++;
	}
	if (!temp->next) {
		cerr << "Out of Range\n";
		return;
	}
	Node* removeNode = temp->next;
	temp->next = removeNode->next;
	delete removeNode;
}
// reverse's the linked list  (Iterative Method)
void LinkedList::reverseList() {
	Node *prevNode = NULL , *nextNode = NULL , *currNode = head ;
	while (currNode) {
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}
	head = prevNode;
}

int main() {
	int n ;
	cin >> n ;
	vector<int> values(n);
	for (auto &v : values) cin >> v ;

	LinkedList list ;
	list.constructList(values);
	list.printList();
	list.deleteNode(4);
	list.printList();
	list.reverseList();
	list.printList();
}