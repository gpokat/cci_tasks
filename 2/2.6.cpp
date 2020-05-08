//Palindrome: Implement a function to check if a linked list is a palindrome.

//The strightford way is to copy input linked list and revers.
//Then compare a half of the linked lists. If they identically - palindrome, etherwise - not.
//For O(N1+N2)

//But in the book show very elegant approach with fast and slow iterators and stak to reverse a left part of LL.
struct Node
{
    int value;  //data
    Node *next; //next pointer

    Node(int v, Node *n) : value(v), next(n)
    {
    }

    //construstor
};

//elegant solution for O(N) runtime and O(N/2) space complexity
bool isPalindrome(Node *header)
{

    Node *fast_iterator = header->next;
    Node *slow_iterator = header->next;
    stack<int> buff;
    //findind the middle node using trick with double step iterator for O(N/2)
    while (fast_iterator != nullptr && fast_iterator->next != nullptr)
    {
        buff.emplace(slow_iterator->value);
        fast_iterator = fast_iterator->next->next; //double step
        slow_iterator = slow_iterator->next;       //normal step
    }

    //if the length of LL is odd, than middle node is shared and compensate byself
    if (fast_iterator != nullptr)
    {
        slow_iterator = slow_iterator->next;
    }

    //LL is 1 2 2 1  <----->
    //buff as stack 1 2 | 2 1
    while (!buff.empty()) //for O(N/2)
    {

        if (buff.top() != slow_iterator->value) //FILO natural revers data structure
            return false;

        buff.pop();                          //remove
        slow_iterator = slow_iterator->next; //going to the next node of the left part of LL
    }

    return true;
}

//revers of LL
void reversLL(Node *header) //reverse funtion
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