//Paths with Sum: You are given a binary tree in which each node contains an integer value (which
//might be positive or negative). Design an algorithm to count the number of paths that sum to a
//given value. The path does not need to start or end at the root or a leaf, but it must go downwards
//(traveling only from parent nodes to child nodes).

struct Node
{

    Node *left_child = nullptr;
    Node *right_child = nullptr;
    int data;

    Node(int d) : data(d)
    {
    }
};

void PrintSeed(vector<Node *> &path, int begin_idx)
{
    for (int i = begin_idx; i < path.size(); ++i)
    {
        cout << path[i]->data << " ";
    }
    cout << "\n";
}

//Runtime is O(N^2) at worst case at the skewed tree (for the last child we have O(N) for path and pre-order O(N)).
//Space is O(height) which related to O(log(N)) due to downward path can't be longer than tree heigth
void simpify_dfs(Node *node, vector<Node *> &path, int given_sum, int &path_counts)
{

    if (node == nullptr)
        return;

    path.push_back(node);
    simpify_dfs(node->left_child, path, given_sum, path_counts);  //going to the bottom by left childs
    simpify_dfs(node->right_child, path, given_sum, path_counts); //if left way was rpocessed going to right childs

    int check_sum = 0;
    for (int i = path.size() - 1; i >= 0; --i)
    { //summurize in reverse order due to pushing to back
        check_sum += path[i]->data;
        if (check_sum == given_sum)
        {
            PrintSeed(path, i);
            path_counts++;
        }
    }
    //backtrack step for path
    path.pop_back();
}

int GetPathCount(Node *root, int given_sum)
{
    vector<Node *> path;
    int path_counts = 0;
    simpify_dfs(root, path, given_sum, path_counts);
    return path_counts;
}
