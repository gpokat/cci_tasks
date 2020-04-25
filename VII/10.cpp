//The answer is O(sizeOf(n))
//According to the termanology it is the O(log(n))
//due to asymptotically assumption of the length of number n.

int sumDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}