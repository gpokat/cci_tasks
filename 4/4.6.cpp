//Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
//binary search tree. You may assume that each node has a link to its parent.

struct Node
{
    Node *left_child = nullptr;
    Node *right_child = nullptr;
    Node *parent = nullptr;
    int data;

    Node(int d, Node *p = nullptr) : data(d), parent(p)
    {
    }
};

void InOrderTraversal(Node *node, vector<Node *> &buffer)
{
    if (node == nullptr)
        return;

    InOrderTraversal(node->left_child, buffer);
    buffer.push_back(node); //O(N) space
    InOrderTraversal(node->right_child, buffer);
}

//simple non-efficient method with extra buffer
//Runtime is O(3*N), Space is O(N) at worst case
Node *InOrderSuccessor(Node *curr_node)
{
    //going back (to the root node) by using a parent link
    Node *root = curr_node;

    while (root->parent != nullptr) //O(N)
    {
        root = root->parent;
    }

    vector<Node *> buff;
    //do in-order traversal from root node & store path into vector
    InOrderTraversal(root, buff); //O(N)

    Node *next_successor;
    auto it = find(buff.begin(), buff.end(), curr_node); //O(N)
    next_successor = (++it != buff.end()) ? *it : nullptr;

    return next_successor;
}

//efficient way w/o extra buffer
//There is 3 cases if we have right&left childs of input node, only right or only left or noone.
// for first case return in-order next node (left-node-right => if we have a node than cycle is node-right-left)
// for second case return just a right child of input node due to absent of left child aka unfull in-order cycle
// for third case we should travers back using by parent links for seeking parent which left child is equal a current node -
//i.e. like-a-rollback the in-order traversal recursion to find the next node.

//Runtime is O(heigth), space is O(1)
Node *InOrderSuccessorE(Node *curr_node)
{
    if (curr_node->right_child != nullptr && curr_node->right_child->left_child != nullptr)
    {
        return curr_node->right_child->left_child;
    }
    else if (curr_node->right_child != nullptr && curr_node->right_child->left_child == nullptr)
    {
        return curr_node->right_child;
    }
    else if (curr_node->right_child == nullptr)
    {
        Node *parent = curr_node->parent;
        while (parent != nullptr)
        { //until root node don't reached
            if (parent->left_child != nullptr && parent->left_child == curr_node)
                return parent;
            curr_node = parent;
            parent = parent->parent;
        }
    }
    return nullptr;
}
