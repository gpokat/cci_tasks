//The answer is O(1) or constant.
//In this case runtime doesn't have dependency of any variable or loop,
//just of number of operations related to each line.

int mod(int a, int b)
{
    if (b <= 0)
    {
        return -1;
    }
    int div = a / b;
    return a - div * b;
}