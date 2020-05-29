//List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
//at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

struct Node
{
    Node *left_child = nullptr;
    Node *right_child = nullptr;
    int data;

    Node(int d) : data(d)
    {
    }
};

vector<forward_list<Node *>> DListsFromBT;

//due to constant structed of BT i.e. each lvl of depth have 2^i nodes, & relation between nodes constant i.e. each node have 2 child (w/o overlaps or
//additional edges). We woudn't check the visibility of nodes. Further we exactly know how many nodes we have at each lvl of depth.
//Travers lvl by lvl from parents-children links aka simplify BFS method.
//The runtime & space is O(N) because of store nodes to the vector/LinkedList & traversal trought all nodes.
void begin_bfs(Node *root)
{
    forward_list<Node *> depth_list;
    DListsFromBT.push_back(depth_list);
    DListsFromBT[0].push_front(root); //zero depth lvl

    while (true)
    {
        for (auto parent : DListsFromBT[DListsFromBT.size() - 1]) //filling new depth lvl using previous parents
        {
            if (parent->left_child)
            {
                depth_list.push_front(parent->left_child);
            }
            if (parent->right_child)
            {
                depth_list.push_front(parent->right_child);
            }
        }
        if (depth_list.empty()) //all childrens processed
            break;
        DListsFromBT.push_back(depth_list); //add new lvl
        depth_list.clear();
    }

    return;
}
