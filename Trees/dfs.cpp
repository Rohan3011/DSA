#include<iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int data ;
	Node *left , *right ;

	Node(int value) {
		this->data = value;
		this->left = this->right = nullptr ;
	}

	Node(int value , Node* left , Node* right) {
		this->data = value;
		this->left = left ;
		this->right = right ;
	}
};



void bfs(Node* root ) {
	queue<Node*> nodes ;
	nodes.push(root);
	while (!nodes.empty()) {
		Node* top = nodes.front();
		nodes.pop() ;
		cout << top->data << " " ;
		if (top->left)
			nodes.push(top->left);
		if (top->right)
			nodes.push(top->right);
	}
	cout << endl ;
}


bool printLevel(Node* root , int level) {
	if (root == nullptr) {
		return  false;
	}
	if (level == 1) {
		cout << root->data << " ";
		return true;
	}
	bool left = printLevel(root->left , level - 1 );
	bool right = printLevel(root->right , level - 1);

	return  left || right;
}

void levelOrderTraversal(Node* root , int level = 1) {
	cout << level <<  ": ";
	while (printLevel(root , level)) {
		level++ ;
		cout << "\n" <<  level <<  ": ";
	}
}


int main()
{

	Node* root = new Node(1);
	root-> left = new Node(2);
	root-> right = new Node(3);
	root-> left->left = new Node(4);
	root-> left->right = new Node(5);
	root-> right->left = new Node(6);
	root-> right->right = new Node(7);

	// bfs(root);
	levelOrderTraversal(root);

}