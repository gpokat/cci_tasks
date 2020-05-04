//Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
//the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
//that node.
//EXAMPLE
//Input: the node c from the linked list a->b->c->d->e->f
//Result: nothing is returned, but the new linked list looks like a->b->d->e->f

struct Node
{
    int value;
    Node *next;

    Node(int value, Node *n) : value(v), next(n)
    {
    }
};

//the simplets solution is just shift the data from the end trought middle node
//i.e. copy data from d to c, change link (pointer) from c to e => c transfered to d, the original d is deleting.
//BigO(1)
void DeleteMiddle(Node *middleNode)
{

    middleNode->value = middleNode->next->value;
    middleNode->next = middleNode->next->next;
}