//The answer is O(numChars^remaining).
//So, the algorithm is generate a strings with 'remaining' length for O(numChars^remaining) times.
//For example: if 2 character required => aa, ab, ba, bb => 2^2.
//Then the algorithm is checked each generated string for O(remaining) times at worst case or less.
//Finally, we have O(numChars^remaining)*O(remaining).

int numChars = 26;

char ithLetter(int i)
{
    return (char)(((int)'a') + i);
}

bool isInOrder(string s)
{
    for (int i = 1; i < s.length(); i++)
    {
        int prev = ithLetter(s[i - 1] - '0');
        int curr = ithLetter(s[i] - '0');

        if (prev > curr)
        {
            return false;
        }
    }
    return true;
}

void printSortedStrings(int remaining, string prefix)
{
    if (remaining == 0)
    {
        if (isInOrder(prefix))
        {
            cout << prefix << endl;
        }
    }
    else
    {
        for (int i = 0; i < numChars; i++)
        {
            char c = ithLetter(i);
            printSortedStrings(remaining - 1, prefix + c);
        }
    }
}

void printSortedStrings(int remaining)
{
    printSortedStrings(remaining, "");
}
