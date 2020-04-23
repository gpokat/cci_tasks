//The runtime is O(sqrt(n)).
//The for loop goes from 1 to guess * guess one by one.
//i.e. number of iteration for sqrt finding equals sqrt(n).

int sqrt(int n)
{
    for (int guess = 1; guess * guess <= n; guess++)
    {
        if (guess * guess == n)
        {
            return guess;
        }
    }
    return -1;
}