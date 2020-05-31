//Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
//this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
//node never differ by more than one.

//Runtime complexity is O(N) due to traverse all tree nodes,
//Space complexity is O(tree heigth) due to size of recursive stack not greater than maximum heigth of tree
//for each call i.e. if we have tree height = 3 that mean stack size equal 3 calls for each calculation of CheckBalancedBT.
//More preciesly for reached that: height = max(left_height, right_height) + 1; 

struct Node
{

	Node *left_child = nullptr;
	Node *right_child = nullptr;
	int data;

	Node(int d) : data(d)
	{
	}
};

//using postOrder traversal i.e. traverse from bottom to up and calculate max heigth of each node (0 or 1) for left sub-tree && right sub-tree.
//check if the difference not great than 2.
bool CheckBalancedBT(Node *root, int &height)
{

	int left_height = 0, right_height = 0; //'sub-heigth' of each node

	if (root == nullptr) //is incorrect node passed stop
		return false;

	CheckBalancedBT(root->left_child, left_height);
	CheckBalancedBT(root->right_child, right_height);

	//extra iteration for root(first up) node => than we must to substruct 1 from final tree heigth (if we want to know it)
	height = max(left_height, right_height) + 1; //traverse&store trought recursion stack height of tree

	if (abs(left_height - right_height) > 1) //stop if tree is not Balanced
		return false;

	return true;
}
