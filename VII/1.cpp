//The runtime of this function is O(b) or O(n).
//In this case runtime depends on number of iterations (b) which this function have to make.

int product(int a, int b)
{
    int sum = 0;
    for (int i = 0; i < b; i++)
    {
        sum += a;
    }
    return sum;
}