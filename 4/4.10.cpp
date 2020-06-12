//Check Subtree: T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an
//algorithm to determine if T2 is a subtree of T1.
//NOTE:
//A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2.
//That is, if you cut off the tree at node n, the two trees would be identical.

struct Node
{

    Node *left_child = nullptr;
    Node *right_child = nullptr;
    int data;

    Node(int d) : data(d)
    {
    }
};

//Solution based on fact what identical Binary Tree could be find if smaller tree is a sub-tree of bigger tree in string notation.
//We flate both of BT to strings using by In-Order & Pre-Order traversal, store them and find a sub-string.
//Runtime and sapace is O(M+N)
void InOrderStore(Node *node, string &str)
{

    if (node == nullptr) return;

    InOrderStore(node->left_child, str);
    str.push_back(node->data);
    InOrderStore(node->right_child, str);
}

void PreOrder(Node *node, string &str)
{

    if (node == nullptr) return;

    str.push_back(node->data);
    PreOrder(node->left_child, str);
    PreOrder(node->right_child, str);
}

bool CheckSubBinaryTree(Node *T1_root, Node *T2_root)
{
    string t1_inOrder, t2_inOrder, t1_PreOrder, t2_PreOrder;

    PreOrder(T1_root, t1_PreOrder);
    PreOrder(T2_root, t2_PreOrder);

    PreOrder(T1_root, t1_inOrder);
    PreOrder(T2_root, t2_inOrder);

    //assume the not a difference between lower&upper case characters.
    //instead do a tolower to a normalize characters.
    return t1_PreOrder.find(t2_PreOrder) != string::npos && t1_inOrder.find(t2_inOrder) != string::npos;
}

//Memory efficient way.
//Runtime is O(M*N), but memory is O(log(N)+log(M))
bool CheckSubBinaryTreeMem(Node *T1_root, Node *T2_root)
{

    if (T1_root == nullptr && T2_root == nullptr) return true; //due to empty nodes in the both of tree
    if (T1_root == nullptr || T2_root == nullptr) return false; //could be presented

    //if data is matched
    //simultaneous go deeper to both of the tree
    //and still compare nodes
    if (T1_root->data == T2_root->data)
        return CheckSubBinaryTreeMem(T1_root->left_child, T2_root->left_child) &&
               CheckSubBinaryTreeMem(T1_root->right_child, T2_root->right_child);

    //if no exactly match
    //check left&right of bigger tree undepedently due to this tree could have
    //more complex structure (more nodes than smaller).
    return CheckSubBinaryTreeMem(T1_root->left_child, T2_root) ||
           CheckSubBinaryTreeMem(T1_root->right_child, T2_root);
}
