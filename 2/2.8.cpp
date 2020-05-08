//Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
//beginning of the loop.
//DEFINITION
//Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
//as to make a loop in the linked list.
//EXAMPLE
//Input: A -> B -> C -> 0 -> E -> C[the same C as earlierl
//Output: C

struct Node
{
    int value;
    Node *next;

    Node(v, n) : value(v), next(n) //aggregation for easy to init LL like
    //Node* header=new Node(-1,new Node(1,new Node(2,new Node(3,new Node(4,nullptr)))));
    {
    }
};

//the solution for O(N) runtime and O(N) space could be reached with set container (buffer). Like for previous 2.7 task.

//fast/slow approach is more elegant and efficient according to the space compexity O(1) and O(2N) runtime
//It is working like ordinary clock i.e. seconds is fast iterator, minutes is slow iterator - they meet once in a minute,
//but seconds it. faster than minutes it. for 60times.
Node *IsLoopExistsAndStartNode(Node *header)
{

    Node *fast_it = header->next;
    Node *slow_it = header->next;

    while (fast_it != nullptr && fast_it->next != nullptr)
    { //O(N)

        fast_it = fast_it->next->next; //2times faster
        slow_it = slow_it->next;

        if (fast_it == slow_it)
            break;
    }

    if (fast_it == nullptr || fast_it->next == nullptr)
    { //LL w/o loop
        return nullptr;
    }

    slow_it = header->next; //setup slow to first node

    while (fast_it != slow_it)
    { //O(N)
        fast_it = fast_it->next;
        slow_it = slow_it->next;
    }

    return fast_it;
}
