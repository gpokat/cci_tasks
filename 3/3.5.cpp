//Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
//an additional temporary stack, but you may not copy the elements into any other data structure
//(such as an array). The stack supports the following operations: push, pop, peek(top), and isEmpty.


//The idea is to swap items between two stacks. It's looks like to mimic 'bubble sort'. 
//The runtime is O(N^2) at worst case and O(N) space complexity due to external buffer.
void SortStack(stack<int> &input_stack)
{
    stack<int> tmp_stack;

    while (!input_stack.empty())
    {
        int st1 = input_stack.top(); //get top item
        input_stack.pop();

        while (!tmp_stack.empty() && st1 > tmp_stack.top()) //until buffer isn't empty and top item larger than top buffer item
                                                            //popping all smallest items from buff and keep it in original stack
        {
            input_stack.push(tmp_stack.top());
            tmp_stack.pop();
        }
        tmp_stack.push(st1); //at this point we could push current smallest item to top of buff stack
    }
    input_stack = tmp_stack; //just copy result
}
