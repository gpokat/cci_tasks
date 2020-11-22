//Rank from Stream: Imagine you are reading in a stream of integers. Periodically, you wish
//to be able to look up the rank of a number x (the number of values less than or equal to x).
//Implement the data structures and algorithms to support these operations. That is , implement
//the method track(int x), which is called when each number is generated, and the method
//getRankOfNumber(int x), which returns the number of values less than or equal to x (not
//including x itself).
//EXAMPLE
//Stream (in order of appearance): 5,1,4,4,5,9,7,13,3
//getRankOfNumber(l) 0
//getRankOfNumber(3) 1
//getRankOfNumber(4) 3


//Binary Search Tree data structure to hold stream data in tree with some order.
//The BST constraints guaratee O(log(N)) runtime access. The rank function calculate
//'rank' using by storing size of nods when it is inserting. So, getRank just traverse trought
//BST to find node and return appropriate size.
//Space is O(N).
struct Node
{
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    int leftSize = 0;

    Node(int data) : data(data)
    {
    }
};

class BST
{
public:
    Node *root;

    Node *insert(int data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
            return root;
        }
        return insert(root, data);
    }

    int getRank(int v)
    {
        if (root != nullptr)
            return getRank(root, v);
        else
            return -1;
    }

private:
Node *insert(Node *node, int data)
    {
        if (node == nullptr)
        {
            node = new Node(data);
            return node;
        }

        if (data <= node->data)
        {
            node->left = insert(node->left, data);
            node->leftSize++;
        }
        else
            node->right = insert(node->right, data);

        return node;
    }

    int getRank(Node *node, int v)
    {

        if (v == node->data)
            return node->leftSize;
        if (v < node->data && node->left != nullptr)
            return getRank(node->left, v);
        if (node->right != nullptr)
            return node->leftSize + 1 + getRank(node->right, v);
        return -1;
    }
};
