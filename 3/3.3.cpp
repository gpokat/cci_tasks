//Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
//Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
//threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
//composed of several stacks and should create a new stack once the previous one exceeds capacity.
//SetOfStacks. push () and SetOfStacks. pop () should behave identically to a single stack
//(that is , pop ( ) should return the same values as it would if there were just a single stack).
//FOLLOW UP
//Implement a function popAt (int index) which performs a pop operation on a specific sub-stack.

//For the mimic that behavior I realise stack as double linked list to control capacity and implement the popAt method with
//top extra nodes which points to the top nodes in each plates.
//This implementation work with heap and one by one allocations - it could be upgraded to more efficient way by using array for storing nodes.
//The popAt method work work O(N) runtime - it could be rejected to O(1) to store extra node to the array.

class StackOfPlates
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node *prev;

        Node()
        {
            next = nullptr;
            prev = nullptr;
        }
    };

    Node *gen_top = nullptr;
    Node *sub_top = nullptr;

    const int stack_capacity;
    int cap_count = 0;

public:
    StackOfPlates(int sz) : stack_capacity(sz)
    {
    }

    void push(int data)
    {

        Node *newNode = new Node();
        newNode->data = data;

        newNode->next = gen_top;
        if (gen_top != nullptr)
            gen_top->prev = newNode;

        gen_top = newNode;

        cap_count++;
        Node *new_sub_top;
        if (cap_count == 1)
        {
            new_sub_top = new Node();

            if (sub_top != nullptr)
                new_sub_top->prev = sub_top;
        }

        new_sub_top->next = gen_top;
        sub_top = new_sub_top;

        if (cap_count == stack_capacity)
            cap_count = 0;
    }

    void pop()
    {

        if (gen_top == nullptr)
            return;

        Node *newTop = gen_top->next;
        if (gen_top->next->prev != nullptr)
            gen_top->next->prev = nullptr;
        Node *oldTop = gen_top;
        gen_top = newTop;
        sub_top->next = gen_top;

        cap_count--;

        if (cap_count == 0)
        {
            Node *old_sub_top = sub_top;
            sub_top = sub_top->prev;
            delete old_sub_top;
        }

        delete oldTop;
    }

    void popAt(int stack_id)
    {
        int stack_count = 1;
        Node *cur_sub_top = sub_top;
        while (cur_sub_top != nullptr)
        {
            if (stack_count == stack_id)
                break;
            stack_count++;
            cur_sub_top = cur_sub_top->prev;
        }

        if (stack_count == 1)
        {
            pop();
            return;
        }
        else
        {

            Node *new_sub_top = cur_sub_top->next->next;
            Node *old_sub_top = cur_sub_top->next;
            cur_sub_top->next->next->prev = cur_sub_top->next->prev;
            cur_sub_top->next->prev->next = cur_sub_top->next->next->prev;
            cur_sub_top->next = new_sub_top;

            cap_count--;
            delete old_sub_top;
        }
    }

    int &top()
    {
        //TODO assert
        return gen_top->data;
    }

    int &topAt(int stack_id)
    {

        //TODO assert

        int stack_count = 1;
        Node *cur_sub_top = sub_top;
        while (cur_sub_top != nullptr)
        {
            if (stack_count == stack_id)
                break;

            stack_count++;
            cur_sub_top = cur_sub_top->prev;
        }
        return cur_sub_top->next->data;
    }
};