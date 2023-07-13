#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
  Node *next;
  int data;
};

class LinkedList {
public:
  LinkedList() { head = NULL; };
  Node *head;
  void construct(vector<int>);
  void insert(int);
  void remove(int);
  void print();
  void reverse();
};

// construct's the linked list with given values
void LinkedList::construct(vector<int> values) {
  for (auto &u : values)
    this->insert(u);
}

// insert's the element at the end (tail)
void LinkedList::insert(int data) {
  Node *newNode = new Node(data);

  if (head == NULL) {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = newNode;
}

// prints the Linked List
void LinkedList::print() {
  Node *temp = head;
  while (temp) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL\n";
}

// delete's the node with given index (zero based)
void LinkedList::remove(int nodeIndex) {
  Node *temp = head;
  if (!nodeIndex) {
    Node *newHead = head->next;
    delete head;
    head = newHead;
    return;
  }
  int index = 0;
  while (index + 1 < nodeIndex && temp->next) {
    temp = temp->next;
    index++;
  }
  if (!temp->next) {
    cerr << "Out of Range\n";
    return;
  }
  Node *removeNode = temp->next;
  temp->next = removeNode->next;
  delete removeNode;
}

// reverse's the linked list  (Iterative Method)
void LinkedList::reverse() {
  Node *prevNode = NULL, *nextNode = NULL, *currNode = head;
  while (currNode) {
    nextNode = currNode->next;
    currNode->next = prevNode;
    prevNode = currNode;
    currNode = nextNode;
  }
  head = prevNode;
}
