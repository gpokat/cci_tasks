//Random Node: You are implementing a binary tree class from scratch which, in addition to
//insert, find, and delete, has a method getRandomNode() which returns a random node
//from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm
//for getRandomNode, and explain how you would implement the rest of the methods.

//for the binary tree this operations should be implemented for O(log(n)) runtime at balanced BT, in the general case for O(N)
class BinaryTree
{
private:
    struct Node
    {
        Node *left_child = nullptr;
        Node *right_child = nullptr;
        int data;

        Node(int d) : data(d)
        {
        }
    };

    Node *root = nullptr;
    size_t sz = 0;

    Node *find_node_traversal(Node *node, int data) //do pre-order traversal compare data if node found return it oterwise return null
    {

        if (node == nullptr)
            return nullptr;

        if (node->data == data)
            return node;
        Node *left = find_node_traversal(node->left_child, data);
        Node *right = find_node_traversal(node->right_child, data);

        if (left != nullptr)  return left;
        if (right != nullptr) return right;

        return nullptr;
    }

    void delete_deepest_node(Node *node) //remove deepest node & set to null parent links
    {
        queue<Node *> binary_tree_q;
        binary_tree_q.push(root);

        while (!binary_tree_q.empty()) //traverse trought whloe tree
        {
            Node *curr_node = binary_tree_q.front();
            binary_tree_q.pop();

            if (curr_node == node) //remove deepest node itself
            {
                curr_node = nullptr;
                delete node;
                return;
            }

            if (curr_node->right_child != nullptr) //remove parent right link to deepest node
            {
                if (curr_node->right_child == node)
                {
                    curr_node->right_child = nullptr;
                    delete node;
                    return;
                }
                else
                    binary_tree_q.push(curr_node->right_child);
            }

            if (curr_node->left_child != nullptr) //remove parent left link to deepest node
            {
                if (curr_node->left_child == node)
                {
                    curr_node->left_child = nullptr;
                    delete node;
                    return;
                }
                else
                    binary_tree_q.push(curr_node->left_child);
            }
        }
    }

    void inOrder_traversal(Node *node) //classic in-order traversal for printini tree
    {
        if (node == nullptr) return;

        inOrder_traversal(node->left_child);
        cout << node->data << " ";
        inOrder_traversal(node->right_child);
    }

public:
    BinaryTree()
    { //ctor
    }

    //filling queue with nodes beginning with root, checking each node from queue for empty
    //place for new node then create a new node in the free place.
    void InsertNode(int data)
    { //So, avg. for n insertions the time is O(n*log(n)) coz it BT builing in the balancing manner
        queue<Node *> binary_tree_q;
        if (!sz) //if the first node was inserted
        {
            root = new Node(data);
            sz++;
            return;
        }
        else
        {
            binary_tree_q.push(root);
            sz++;
        }

        while (!binary_tree_q.empty())
        {
            Node *parent = binary_tree_q.front();
            binary_tree_q.pop();

            if (parent->left_child == nullptr)
            {
                parent->left_child = new Node(data);
                return;
            }
            else
                binary_tree_q.push(parent->left_child);

            if (parent->right_child == nullptr)
            {
                parent->right_child = new Node(data);

                return;
            }
            else
                binary_tree_q.push(parent->right_child);
        }
    }

    Node *FindNode(int data) //pre-order traversal for node finding
    {
        return find_node_traversal(root, data);
    }


    void DeleteNode(int data) // the O(2*N*log(N)) due to we control a balance of the tree:
                              // instead of stright deleting node, we delete deepest node and swap data with interest node (i.e. swap-remove nodes)
    {
        if (sz == 1 && root->data == data) //if try to delete the last one node aka root
        {
            delete root;
            root = nullptr;
            sz = 0;
            return;
        }

        sz--;

        queue<Node *> binary_tree_q;
        binary_tree_q.push(root);

        Node *node = nullptr;
        Node *deepest_node = nullptr;
        while (!binary_tree_q.empty()) //traverse trought whole tree
        {
            deepest_node = binary_tree_q.front(); //find deepest node
            binary_tree_q.pop();

            if (deepest_node->data == data) //if current node is interest node then remind it
                node = deepest_node;

            if (deepest_node->left_child != nullptr)
                binary_tree_q.push(deepest_node->left_child);

            if (deepest_node->right_child != nullptr)
                binary_tree_q.push(deepest_node->right_child);
        }

        if (node != nullptr) //finally we find a node which must be deleted & deepest node in the tree
        {
            int d = deepest_node->data;
            delete_deepest_node(deepest_node); //remove deepest node
            node->data = d;                    //swap data between deepest & interest nodes
        }
    }

    Node *getRandomNode() //return ranodm node of the tree
    {
        //generate random number from 0 to the tree size (sz)
        int rndm_idx = 12; //some random int generator (bug still exist with gcc.exe (MinGW.org GCC-8.2.0-5) 8.2.0)

        int rndm_count = 0;
        queue<Node *> binary_tree_q;
        binary_tree_q.push(root);

        while (!binary_tree_q.empty())
        {
            Node *node = binary_tree_q.front();
            binary_tree_q.pop();

            if (rndm_idx == rndm_count) return node;

            if (node->left_child != nullptr)
                binary_tree_q.push(node->left_child);
            if (node->right_child != nullptr)
                binary_tree_q.push(node->right_child);
            rndm_count++;
        }
        return nullptr;
    }

    Node *GetRoot() //tree root getter
    {
        if (sz > 0)
            return root;
        else
            throw runtime_error(string("tree is empty"));
    }

    size_t GetSize() //tree size getter
    {
        return sz;
    }

    void PrintTree() //printing method
    {
        inOrder_traversal(root);
    }
};
