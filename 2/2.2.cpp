//Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

struct Node
{
    int value;  //data member
    Node *next; //pointer (link) to the next node

    Node(int v, Node *n) : value(v),
                           next(n) //constr for reverse initialization
    {
    }
};

//The solution from the book.
//More efficient and elegant !

Node *KthToLast(int k)
{
    Node *cur_node = header->next;
    Node *kth_node = header->next;

    for (int i = 0; i < k; i++) //make distance Kth size in the begin using by two iterator
    {
        if (cur_node == nullptr)
            return nullptr;
        cur_node = cur_node->next;
    }

    while (cur_node != nullptr) //just travers trought linked list to the end bouth of iteraitors
    {
        cur_node = cur_node->next;
        kth_node = kth_node->next; //this one is save our distance and pointed to the Kth node at the end of LL
    }

    return kth_node;
}

//the approach base on filling the array and than get a reverse number of kth to last element.
//O(N) runtime and O(N) space complexity
Node *KthToLast(int k)
{

    vector<Node *> buff;
    Node *cur_node = header->next;
    while (cur_node != nullptr) //traverse trought linked list
    {
        buff.emplace_back(cur_node); //fill array
        cur_node = cur_node->next;
    }

    int kth_index = buff.size() - k; //calculate revers number accordigly to the Kth
    if (kth_index >= 0)              //simple check a existins of bounds
        return buff[kth_index];
    else
        return nullptr;
}
