//First Common Ancestor: Design an algorithm and write code to find the first common ancestor
//of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
//necessarily a binary search tree.

struct Node
{
    Node *left_child = nullptr;
    Node *right_child = nullptr;

    int data;

    Node(int d) : data(d)
    {
    }
};

//Runtim is O(2*N) at worst case, space is O(heigth) due to recursive stack size.
//Safe-method to do a check exist input node in the tree or not using by pre-order traversal
bool PreOrderCheck(Node *root, Node *node)
{ //O(N) at worst case

    if (root == node)
        return true;
    if (root == nullptr || node == nullptr)
        return false;

    return PreOrderCheck(root->left_child, node) || PreOrderCheck(root->right_child, node);
}

//traverse tree simulatenously to find first or common ancestor.
//going to bottom of the tree i.e. find previous (parent) node of the successor - it is a ancestor.
//than compare it with initial nodes and decide what return.
Node *FirstCommonAncestor(Node *node, Node *left_successor, Node *right_successor)
{ //O(N)

    if (node == nullptr)
        return nullptr;

    if (node == left_successor || node == right_successor)
        return node;

    Node *left_CA = FirstCommonAncestor(node->left_child, left_successor, right_successor);
    Node *right_CA = FirstCommonAncestor(node->right_child, left_successor, right_successor);

    if (left_CA != nullptr && right_CA != nullptr)
        return node;

    return (left_CA != nullptr) ? left_CA : right_CA;
}

Node *FCA(Node *root, Node *ls, Node *rs)
{

    if (PreOrderCheck(root, ls) && PreOrderCheck(root, rs)) //if nodes in the tree, do search
    {
        return FirstCommonAncestor(root, ls, rs);
    }
    throw runtime_error(string("One of the nodes are not presented in the tree !")); //if not - return exeption
}
