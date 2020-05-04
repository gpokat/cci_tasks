//Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
//before all nodes greater than or equal to x. lf x is contained within the list, the values of x only need
//to be after the elements less than x (see below). The partition element x can appear anywhere in the
//"right partition "; it does not need to appear between the left and right partitions.
//EXAMPLE
//Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5)
//Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

struct Node
{
    int value;
    Node *next;
};

//for ideal partition it could be a classical bubble sort for O(N^2) time and O(1) space.
//According to the task, there is not requirement ideal , i.e. we mustn't do an sort a elements
//Made a two linked lists for with condition >= partition / else and linked in together - it's simple, but need a additional sapce.
//The book idea based on changing links of existing nodes to the first/last nodes and adding to them other nodes by condition
//runtime O(N), space O(1)
Node *DoPartition(int part_value)
{

    Node *cur_node = header->next;
    Node *first_node = header->next;
    Node *last_node = header->next;

    while (cur_node != nullptr)
    {
        Node *next_node = cur_node->next;

        if (cur_node->value < part_value)
        { //leftside part of LL
            cur_node->next = first_node;
            first_node = cur_node;
        }
        else
        { //rightside of LL
            last_node->next = cur_node;
            last_node = cur_node;
        }

        cur_node = next_node;
    }
    last_node->next = nullptr;

    header->next=first_node; //add original header

    return header; //aka new header
}