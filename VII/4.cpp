
//The answer is O(a/b) or variable runtime.
//The number of iteration which have to make loop depend on a/b.
//i.e. sum increasing each iteration by b until loop condition true (sum <= a).

int div(int a, int b)
{
    int count = 0;
    int sum = b;

    while (sum <= a)
    {
        sum += b;
        count++;
    }
    return count;
}