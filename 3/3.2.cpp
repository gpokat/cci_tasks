//Stack Min: How would you design a stack which, in addition to push and pop, has a function min
//which returns the minimum element? Push, pop and min should all operate in 0(1) time.


//The implementation based on sigle linked list (SLL) with additional keeping a SLL for the 'min data'.
//It working with heap and one by one allocation which could be reingeniring to the more efficient way (preallocation)

class StackWMin
{

private:
    struct Node
    {
        int data;
        Node *next;

        Node(int d) : data(d)
        {
        }
    };

    Node *mins = nullptr;
    Node *tops = nullptr;

public:
    void push(int data)
    { //allocate memory one by one in heap. (could be change to better performance)
        Node *newNode = new Node(data);

        //init - for empty stack
        if (tops == nullptr)
        {
            tops = newNode;
            mins = tops;
            return;
        }

        //add new min node for reminding previous mins in stack
        if (data < mins->data)
        {
            Node *newMin = new Node(data);
            newMin->next = mins;
            mins = newMin;
        }

        //connect new top node
        newNode->next = tops;
        tops = newNode;
    }

    void pop()
    {

        if (tops == nullptr)
        {
            return;
        }

        Node *prev = tops->next;
        Node *top_node = tops;
        tops = prev;

        Node *min_node = mins;
        if (top_node->data == mins->data)
        {
            mins = mins->next;
            delete min_node;
        }

        delete top_node; //free allocated memory
    }

    int &top()
    {
        return tops->data;
    }

    int &min()
    {
        return mins->data;
    }
};
