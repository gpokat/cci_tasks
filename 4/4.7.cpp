//Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of
//projects, where the second project is dependent on the first project ). All of a project's dependencies
//must be built before the project is. Find a build order that will allow the projects to be built. If there
//is no valid build order, return an error.
//EXAMPLE
//Input:
//projects: a, b, c, d, e, f
//dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
//Output: f, e, a, b, d, c

struct Node
{
    //some data
    string proj_name;
    //...

    Node(string name) : proj_name(name)
    {
    }
};
typedef pair<Node *, vector<Node *>> vertex; //aka node of graph


//using recursive DFS with constrainst.
//Runtime is O(P+D) which equvivalent O(V+E) in graphs therminology.
//Space is O(V+E) due to store each vertex & their dependencies(i.e. edges).
class BuildOrder
{
private:
    vector<vertex> graph;                      //graph representation
    vector<Node *> *proj_list;                 //initial project list
    vector<pair<Node *, Node *>> *depend_list; //initial dependence list
    vector<vertex> order;                      //Result order list
    map<Node *, int> mapping;                  // idexes for graph
    vector<bool> visited;                      //visited control list
    size_t psize = 0;                          //size of projects
    int recursive_control = 0;                 //recursive stop condition

    void MakeGraphFromData() //forming graph frot inital data
    {
        for (int idx = 0; idx < psize; idx++) //filling graph with projects. remind indexes
        {
            Node *project = (*proj_list)[idx];
            graph.push_back(make_pair(project, vector<Node *>()));
            mapping.insert(make_pair(project, idx));
        }

        for (int idx = 0; idx < depend_list->size(); idx++) //adding to the graph's nodes dependencies childs
        {
            pair<Node *, Node *> proj_dep = (*depend_list)[idx];
            if (proj_dep.first == proj_dep.second)
                throw runtime_error(string("Building an order not possible with self-loop projects!")); //self-loop detection
            graph[mapping[proj_dep.first]].second.push_back(proj_dep.second);
        }

        visited.reserve(psize);
        for (int idx = 0; idx < psize; idx++) //initialize visit control list
        {
            visited.emplace_back(false);
        }

        return;
    }

    //recursive DFS search with visit constraints
    bool begin_dfs(vertex *vtx)
    {
        recursive_control++;
        if (order.size() == psize)
            return true;

        if (recursive_control > psize * 3)
            return false; //stop recursive if stack if too big

        int vtx_idx = mapping[vtx->first];

        if (!visited[vtx_idx])
        {
            bool all_childs_covered = true;
            for (int jdx = 0; jdx < vtx->second.size(); jdx++) //check constraint
            {
                vertex *child = &graph[mapping[vtx->second[jdx]]];
                all_childs_covered *= visited[mapping[child->first]];
            }

            if (all_childs_covered) //if all dependencies are processed than push project to order list
            {
                order.push_back(*vtx);
                visited[vtx_idx] = true; //mark project as done
            }
        }

        for (int jdx = 0; jdx < vtx->second.size(); jdx++) //traverse to bottom of graph i.e. scan graph as tree from up to down
        {
            vertex *child = &graph[mapping[vtx->second[jdx]]];

            if (!visited[mapping[child->first]]) //if not visited yet
            {
                return begin_dfs(child); //process next deeper node
            }
        }

        //if going deeper not possible than try to do with another project
        vtx_idx = (vtx_idx + 1 >= psize) ? 0 : vtx_idx + 1;

        return begin_dfs(&graph[vtx_idx]);
    }

public:
    BuildOrder(vector<Node *> *pl, vector<pair<Node *, Node *>> *dl) : proj_list(pl), depend_list(dl)
    {
        psize = pl->size();
    }

    vector<vertex> Build()
    {
        MakeGraphFromData();

        bool success = begin_dfs(&graph[0]);
        if (success)
            return order;
        else
            throw runtime_error(string("Building an order not possible !"));
    }
};