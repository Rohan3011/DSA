export class BinaryTreeNode<T> {
  data: T;
  leftNode?: BinaryTreeNode<T>;
  rightNode?: BinaryTreeNode<T>;


  constructor(data: T) {
    this.data = data;
  }
}

export class BinarySearchTree<T> {
  root?: BinaryTreeNode<T>;

  comparator: (a: T, b: T) => number;


  /**
   * preorder traversal
   */
  public preorder(root: BinaryTreeNode<T>|undefined) {
    if (root === undefined) return;
    console.log(` ${root.data}`);
    this.preorder(root.left);
   this.preorder(root.right);
  }

  /**
   * inorder
   */
  public inorder(root: BinaryTreeNode<T>|undefined) {
    if (root === undefined) return;
    this.inorder(root.left);
    console.log(` ${root.data}`);
    this.inorder(root.right);
  }

  /**
   * postorder
   */
  public postorder(root: BinaryTreeNode<T>|undefined) {
    if (root === undefined) return;
    this.postorder(root.left);
    this.postorder(root.right);
    console.log(` ${root.data}`);
  }
}


function main() {
  node: BinaryTreeNode<T> = new Node()
}
