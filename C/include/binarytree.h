/*
 * binarytree.h
 *
 */

struct BinarySearchTreeNode{
	int value;
	struct BinarySearchTreeNode *left, *right;
};

struct BinarySearchTree{
	struct BinarySearchTreeNode *root;
	int no;
};

// List of functions.
void PrintInOrder(struct BinarySearchTreeNode *Curr);
void PrintPreOrder(struct BinarySearchTreeNode *Curr);
void PrintPostOrder(struct BinarySearchTreeNode *Curr);
struct BinarySearchTreeNode * AddNode(struct BinarySearchTreeNode *Curr, int value);
int CreateTree(struct BinarySearchTree *MyTree, int a[], int n);
int InitializeTree(struct BinarySearchTree *MyTree);

// Other functions.
void BinarySearchTreeMenu();

// End of Header.

