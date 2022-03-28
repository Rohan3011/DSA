class Node:
    def __init__(self, value):
        self.left: Node = None
        self.right: Node = None
        self.data = value

    def preorder(self):
        print(self.data, end=' ')
        if self.left:
            self.left.preorder()
        if self.right:
            self.right.preorder()

    def inorder(self):
        if self.left:
            self.left.preorder()
        print(self.data, end=' ')
        if self.right:
            self.right.preorder()

    def postorder(self):
        if self.left:
            self.left.preorder()
        if self.right:
            self.right.preorder()
        print(self.data, end=' ')


def main():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)

    print("Preorder traversal: ", end="")
    root.preorder()
    print()
    print("inorder traversal: ", end="")
    root.inorder()
    print()
    print("postorder traversal: ", end="")
    root.postorder()


if __name__ == '__main__':
    main()
