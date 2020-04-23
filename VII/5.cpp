
//The answer is O(log(n)).
//The each iteration is divided n by factor 2 => at k iter it is n=2^k;
//Thats why k=log2(n) or just a log(n)

int sqrt_helper(int n, int min, int max)
{
    if (max < min)
        return -1;

    int guess = (min + max) / 2;

    if (guess * guess == n)
    {
        return guess;
    }
    else if (guess * guess < n)
    {
        return sqrt_helper(n, guess + 1, max);
    }
    else
    {
        return sqrt_helper(n, min, guess - 1);
    }
}

int sqrt(int n)
{
    return sqrt_helper(n, 1, n);
}
