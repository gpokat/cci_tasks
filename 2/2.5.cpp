//Sum Lists: You have two numbers represented by a linked list, where each node contains a single
//digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a
//function that adds the two numbers and returns the sum as a linked list.
//EXAMPLE
//Input: (7-> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
//Output: 2 -> 1 -> 9. That is, 912.
//FOLLOW UP
//Suppose the digits are stored in forward order. Repeat the above problem.
//EXAMPLE
//Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is,617 + 295.
//Output: 9 -> 1 -> 2. That is, 912.

struct Node
{
    int value;  //data member
    Node *next; //pointer (link) to the next node

    Node(int v, Node *n) : value(v),
                           next(n) //constr for init
    {
    }

    Node(int v) : value(v)
    { //for doSum
        next = nullptr;
    }
};

//The idea is to use school mathematics to do a addition digit by digit like BigIntegerArithmetic for strings
Node *DoSum(Node *header1, Node *header2) //O(N1+N2)
{

    Node *res = new Node(-1); //header
    Node *res_header = res;

    Node *cur_node1 = header1;
    Node *cur_node2 = header2;

    int sum = 0;
    while (cur_node1->next != nullptr && cur_node2->next != nullptr) //iterate trought lists until the end
    {
        int value1 = 0;
        int value2 = 0;

        if (cur_node1->next != nullptr)
        {
            cur_node1 = cur_node1->next;
            value1 = cur_node1->value;
        }

        if (cur_node2->next != nullptr)
        {
            cur_node2 = cur_node2->next;
            value2 = cur_node2->value;
        }

        sum += value1 + value2;  //aum for digit by digit
        int reminder = sum % 10; //calculate raminder

        if (sum > 9) //if >=10
        {
            sum = 1;
            res->next = new Node(reminder);
        }
        else
        {
            res->next = new Node(sum);
            sum = 0;
        }
        res = res->next;
    }

    res->next = nullptr;

    return res_header;
}

//FOLLOW UP
//Ok, in the book this problem solve using by recursion with length of LL (?) 
//We could just add to the previous approach a method to reverse a linked list
void reversLL(Node *header) //Add to O(N1+N2)+O(N1+N2)
{

    Node *cur_node = header->next;
    Node *prev_node = nullptr;
    Node *next;

    while (cur_node != nullptr)
    {

        next = cur_node->next;
        cur_node->next = prev_node;
        prev_node = cur_node;
        cur_node = next;
    }
    header->next = prev_node;
}