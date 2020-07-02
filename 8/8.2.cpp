//Robot in a Grid: Imagine a robot sitting on the upper left corner of grid with r rows and c columns.
//The robot can only move in two directions, right and down, but certain cells are "off limits" such that
//the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to
//the bottom right.

struct Grid
{
    Grid *down = nullptr;  //next row member
    Grid *right = nullptr; //next col member
    bool visited = false;  //visibility
    bool available = true; //availability

    Grid()
    {
    }
};

//Implementation DFS with backtrack
//Because problem is to going from left to right (constraint), the backsteps like up/left not necessary if backsteps doing by backtrack technique.
//So, roughly going deeper and check next step availability if can't going to next down-left pair do backtrack.
//The runtime is ~ O(2*N), space is O(1) w/o path or O(2*N) with.
vector<Grid *> path;

void dfs(Grid *cell)
{

    cell->visited = true;
    path.push_back(cell);

    if (cell->down != nullptr && cell->down->available)
        dfs(cell->down);
    //point out from recursion
    if (path.back()->down == nullptr && path.back()->right == nullptr)
        return;

    if (cell->right != nullptr && cell->right->available)
        dfs(cell->right);
    //point out from recursion

    if (path.back()->down == nullptr && path.back()->right == nullptr)
        return;

    cell->visited = false; //backtrack
    path.pop_back();

    if (path.size() == 0)
        throw runtime_error("can't finde path");

    return;
}
