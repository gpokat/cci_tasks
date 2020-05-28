//Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algorithm
//to create a binary search tree with minimal height.

//Binary Tree (BT) it is a generally non-linear tree which node have one or two children.
//Binary Search Three (BST) it is a sorted BT where left child less than parent and right children greater.

//Height it is a longest path from root to children of the tree.
//Min. height for BST is calculated like floor(log2(N)).
//Max. height for BST is calcilated like N-1.
//The N is calculated like (2^(heigth+1))-1. Explanation - minus 1 due to root node woudn't be calculated, base 2 due to maximum
//two children possible, heigth is number of levels.

//So, obviously for reaching out of minimal height of BST I should pack each level of tree with two children if it possible.
//Recursive solution is implemented by using dividing of array by two parts.
//Due to input array sorted in increase order and has a unique elements I could starting forming MHBST w/o any pre-processing.

//Runtime & Space complexity is O(n) - we must processes(get access, create node, link childrens) each element in the array.

class BST
{
private:
    struct Node
    {
        Node *left_child;
        Node *right_child;
        int data;

        Node(int d) : data(d)
        {
            left_child = nullptr;
            right_child = nullptr;
        }
    };

    int *inarr;
    size_t sz;

    //recursive
    Node *FormMinHeightBST(int begin_idx, int end_idx)
    {
        if (begin_idx > end_idx) //stop recursion (overlap) due to in the left sub-tree end_idx decreases
            return nullptr;      //and in the right sub-tree begin_dx increases to the caverage of whole array will be when
                                 //indexes both became equal (the last elemnt processed) i.e. if we have overlap - than we should stop recursion.

        int parent_idx = (begin_idx + end_idx) / 2;

        Node *node = new Node(inarr[parent_idx]);                       //create new parent node (middle) & set data
        node->left_child = FormMinHeightBST(begin_idx, parent_idx - 1); //make left(smaller children) sub-tree
        node->right_child = FormMinHeightBST(parent_idx + 1, end_idx);  //make right(greater children) sub-tree

        return node;
    }

public:
    Node *root = nullptr;

    BST(int *arr, int arsz) : inarr(arr), sz(arsz)
    {
        if (sz <= 0)
        {
            cout << "array size is incomplite !" << endl;
            exit(0);
        }
    }

    //call method for recursive function
    void FormMinHeightBST()
    {
        int begin_idx = 0;
        int end_idx = sz - 1;
        root = FormMinHeightBST(begin_idx, end_idx);
    }

    Node *GetRootNode()
    {
        return root;
    }
};
