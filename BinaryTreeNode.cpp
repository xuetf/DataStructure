template<typename T>
class BinaryTreeNode {
	friend visit(BinaryTreeNode<T> *);
	friend void InOrder(BinaryTreeNode<T> *);
	friend void PreOrder(BinaryTreeNode<T> *);
	friend void PostOrder(BinaryTreeNode<T> *);
	friend void LevelOrder(BinaryTreeNode<T> *);
	friend void main(void);

public:
	BinaryTreeNode() { LeftChild = RightChild = NULL; }
	BinaryTreeNode(const T& e) {
		data = e;
		LeftChild = RightChild = NULL;
	}
private:
	T data;
	BinaryTreeNode<T> *LeftChild;
	BinaryTreeNode<T> *RightChild;
};