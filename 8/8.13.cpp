//Stack of Boxes: You have a stack of n boxes, with widths w1 heights h1 and depths d1. The boxes
//cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly
//larger than the box above it in width, height, and depth. Implement a method to compute the
//height of the tallest possible stack. The height of a stack is the sum of the heights of each box.


//Just using brute-force approach. Obviously the heightest stack can be reached if we pick the largest box
//by each side everytime and stack it. Due to strictly size requariments some boxes can't be placed in the stack.
//The runtime is O(N^2), space is O(N) due to new stack. The space complexity could be optimize to O(1) using the same
//storage with swap-erase approach, but for additional time costs.


struct Box
{
    int w, h, d;
};

vector<Box> boxes = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
static stack<Box> box_stack;
static int max_height = 0;

void BoxStackFinder()
{

    while (boxes.size() > 0)
    { //O(N)

        Box greater_now = boxes[0];
        auto it_greater = boxes.begin();
        for (auto it_box = boxes.begin(); it_box != boxes.end(); ++it_box)
        { //O(N)
            if (greater_now.w < (*it_box).w && greater_now.h < (*it_box).h && greater_now.d < (*it_box).d)
            {
                greater_now = (*it_box);
                it_greater = it_box;
            }
        }
        if (!box_stack.empty())
        {
            if (greater_now.w < box_stack.top().w && greater_now.h < box_stack.top().h && greater_now.d < box_stack.top().d)
            {//Double-check. consider about some equal side of boxes
                box_stack.push(greater_now);
                max_height += greater_now.h;
            }
        }
        else
        {
            box_stack.push(greater_now);
            max_height += greater_now.h;
        }

        boxes.erase(it_greater);
    }

    cout << max_height << endl;
/*
    while (!box_stack.empty())
    {
        cout << box_stack.top().w << "," << box_stack.top().h << "," << box_stack.top().d << " -- ";
        box_stack.pop();
    }
*/
}