//Coins: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and
//pennies (1 cent), write code to calculate the number of ways of representing n cents.

//Exploring dynamic programming approach like Fibonacci-number
//Runtime is O(n_cents*changes_size), space is O(n_cents)
int CoinsChange(int n_cents)
{
    vector<int> changed_ways(n_cents + 1, 0); //allocate with zeros
    changed_ways[0] = 1;

    for (int i = 0; i < changes_size; ++i) //process each coin
    {
        for (int j = 1; j <= n_cents; ++j) //for each coin add change coin
        {
            if (j >= changes[i]) //add change coin only if it possible i.e. n_cents have enough space to be changed
            {
                changed_ways[j] = changed_ways[j] + changed_ways[j - changes[i]]; //like mapping so
            }
        }
    }

    return changed_ways[n_cents];
}
