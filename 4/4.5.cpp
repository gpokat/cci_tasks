//Validate BST: Implement a function to check if a binary tree is a binary search tree.

struct Node
{   Node* left_child=nullptr;
    Node* right_child=nullptr;
    int data;

    Node(int d):data(d){

    }
};

//The idea is to going down to the bottom of the tree using nullptr init. value of left/right than
//necessary & sufficient is to compare each node with parent-data to decide balanced tree or not
//Runtime is O(N), Space is O(N) due to recursive stack
bool ValidateBST(Node* root, Node* left=nullptr, Node* right=nullptr){

if(root==nullptr) return true; //return true if node doesn't exist

if(left!=nullptr && root->data <= left->data) return false; 
if(right!=nullptr && root->data >= right->data) return false;

return ValidateBST(root->left_child,left,root) && ValidateBST(root->right_child,root,right);

}
