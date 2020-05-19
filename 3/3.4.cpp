//Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.

//Queue is a data structure which based on FIFO (First In - First Out) principle.
//The implementation based on transfer data from one stack to another atleast two times. It's operation sort data to reverse order as natural.
//The call of s1_to_s2 need for revers first stack, the call of s2_to_s1 need for return to previous state to allow MyQueue push further.
//The front, back, pop operations goes for O(1) runtime instead of push operation which goes for O(N^2).
//It could be reduced to O(N) if implementation will be 'lazy' - on call s1_to_s2 and call destructor.

class MyQueue
{

private:
    stack<int> stack1, stack2;

    int *fback;

    void s1_to_s2()
    {
        bool first = true;
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
            if (first)
            {
                fback = &stack2.top();
                first = false;
            }
        }
    }

    void s2_to_s1()
    {
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

public:
    MyQueue() : fback(nullptr)
    {
    }

    void push(int data)
    {
        if (!stack2.empty())
            s2_to_s1();

        stack1.push(data);

        if (!stack1.empty())
            s1_to_s2();
    }

    void pop()
    {
        stack2.pop();
    }

    int &front()
    {
        return stack2.top();
    }

    int &back()
    {
        return *fback;
    }
};
