//Remove Dups: Write code to remove duplicates from an unsorted linked list.
//FOLLOW UP
//How would you solve this problem if a temporary buffer is not allowed?

struct Node
{
    Node *next;
    int value; //the data member

    //initialize constructor (set up next to nullptr by default)
    //need for right init. the node members
};

//Node *header=new Node();
//header->next=first_node;
//header->value=nullptr;

//with extra buffer
void RemoveDuplicatesFromULL()
{

    Node *cur_node = header->next; //first_node
    Node *prev_node = header;

    vector<int> buff;
    //traversal throught linkedlist
    while (cur_node != nullptr)
    {

        int cur_value = cur_node->value;
        if (find(buff.begin(), buff.end(), cur_value) == buff.end())
        {
            buff.emplace_back(cur_value);
            prev_node = cur_node;
        }
        else
        {
            prev_node->next = cur_node->next;
        }

        cur_node = cur_node->next;
    }
}

//FOLLOW UP
//without extra buffer
//avoid buffer, but add one extra loop
void RemoveDuplicatesFromULL()
{

    //vector<int> buff;
    Node *tmp_node = header->next;
    //traversal throught linkedlist //extra cycle
    while (tmp_node != nullptr)
    {

        Node *cur_node = tmp_node->next; //first_node
        Node *prev_node = tmp_node;
        //traversal throught linkedlist
        while (cur_node != nullptr)
        {

            int cur_value = cur_node->value;
            //if (find(buff.begin(), buff.end(), cur_value) == buff.end())
            if (tmp_node->value != cur_value)
            {
                // buff.emplace_back(cur_value);
                prev_node = cur_node;
            }
            else
            {
                prev_node->next = cur_node->next;
            }

            cur_node = cur_node->next;
        }
        tmp_node = tmp_node->next;
    }
}