//Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

//There is two ways to do it. BFS & DFS approaches.
//The method is to start with first vertex what we interested, traverse through graph using DFS/BFS and
//stop if we reached out second interested vertex otherwise return false.

//Runtime is O(Vertexes+Edges) for both of methods.
//Space complexity is O(Vertexes) at worst case for both of methods - dependent of how traversal does.

typedef vector<vector<bool>> adj_mtx; //symmetric adjacency matrix - graph representation

class GraphTraversal
{

private:
    struct vertex
    {
        int data;
        bool vis;
        int idx;
        forward_list<vertex *> child;

        vertex(int d, bool v, int id = -1) : data(d), vis(v), idx(id)
        {
        }
    };

    vector<vertex *> graph; //graph parent-children(tree) representaion by adjacency matrix
    queue<vertex *> q_bfs; //queue for BFS
    stack<vertex *> s_dfs; //stack for DFS
    int vtx_sz;

public:
    GraphTraversal(adj_mtx &a_mtx) : vtx_sz(a_mtx.size()) //build graph like tree
    {
        graph.reserve(vtx_sz);

        for (int ivtx = 0; ivtx < vtx_sz; ++ivtx)
        {
            graph.push_back(new vertex(ivtx + 1, false, ivtx + 1));
        }

        int vtx_count = 0;
        for (int ivtx = 0; ivtx < vtx_sz; ++ivtx)
        {
            vertex *vtx = graph[ivtx]; //parent
            for (int jvtx = 0; jvtx < vtx_sz; ++jvtx)
            {
                if (a_mtx[ivtx][jvtx])
                {
                    vtx->child.push_front(graph[jvtx]); //childrens
                }
            }
        }
    } //ctor

    ~GraphTraversal()
    {
        for (auto v : graph)
        {
            delete v;
        }

        graph.clear();
    }

    bool begin_bfs(int vtx_start, int vtx_end) //find path between vertices usign Bread-First Search
    {
        vertex *begin_vtx = graph[vtx_start - 1];
        begin_vtx->vis = true;
        q_bfs.push(begin_vtx); //enqueue

        while (!q_bfs.empty())
        {
            vertex *current_vtx = q_bfs.front();
            q_bfs.pop(); //dequeue

            if (current_vtx == graph[vtx_end - 1]) //if path found
                return true;

            for (auto child : current_vtx->child) //'breadth' visiting child nodes
            {
                if (!(child->vis))
                {
                    child->vis = true;
                    q_bfs.push(child);
                }
            }
        }

        return false; //if path not found aka visiting all nodes
    }

    //iterative implementation. stack used
    bool begin_dfs(int vtx_start, int vtx_end)
    { //find path between vertices using by Depth-First Search

        vertex *begin_vtx = graph[vtx_start - 1];
        s_dfs.push(begin_vtx);

        while (!s_dfs.empty())
        {

            vertex *current_vtx = s_dfs.top();
            s_dfs.pop();

            if (current_vtx == graph[vtx_end - 1])
            { //if path found
                return true;
            }

            if (!(current_vtx->vis))
                current_vtx->vis = true;

            for (auto child : current_vtx->child) //'depth' visiting child nodes
            {
                if (!(child->vis))
                s_dfs.push(child);
            }
        }
        return false; //if path not found aka visiting all nodes
    }

    //recursive implementation
    bool begin_dfs_r(int vtx_start, int vtx_end)
    { //find path between vertices using by Depth-First Search

        vertex *current_vtx = graph[vtx_start - 1];
        current_vtx->vis = true;

        if (current_vtx == graph[vtx_end - 1])
        { //if path found
            return true;
        }

        for (auto child : current_vtx->child) //'depth' visiting child nodes
        {
            if (!(child->vis))
            {
                return begin_dfs_r(child->idx, vtx_end);
            }
        }

        return false; //if path not found aka visiting all nodes
    }
};