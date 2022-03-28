#include <iostream>
using namespace std;

struct node {
  int data;
  node *left;
  node *right;

  // constructor
  node(int val) {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

class BinaryTree {
public:
  // Traverse Preorder
  void traversePreorder(node *root) {
    if (!root)
      return;
    cout << " " << root->data;
    traversePreorder(root->left);
    traversePreorder(root->right);
  }

  // Traverse Inorder
  void traverseInorder(node *root) {
    if (!root)
      return;
    traverseInorder(root->left);
    cout << " " << root->data;
    traverseInorder(root->right);
  }

  // Traverse Postorder
  void traversePostorder(node *root) {
    if (!root)
      return;
    traverseInorder(root->left);
    traverseInorder(root->right);
    cout << " " << root->data;
  }
};

int main() {
  /*
           0
         /   \
        1     2
      /	\  /  \
    3  	4  5   6

  */

  node *root = new node(0);
  root->left = new node(1);
  root->right = new node(2);
  root->left->left = new node(3);
  root->left->right = new node(4);
  root->right->left = new node(5);
  root->right->right = new node(6);

  BinaryTree binaryTree = BinaryTree();
  binaryTree.traversePreorder(root);
  cout << std::endl;
  binaryTree.traverseInorder(root);
  cout << std::endl;
  binaryTree.traversePostorder(root);
}

/*
        pre : print before any recursive calls
        in : print in between left and right call
        post : print after both the calls
*/