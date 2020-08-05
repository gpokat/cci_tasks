//Permutations without Dups: Write a method to compute all permutations of a string of unique characters.

//heap algortihm for generation permutations
//fast, elegant and simple!
//The idea is to generate call stacks for each of character then permute elements dependence of position&number of stack count.
//The runtime is O(N*N!), space is O(1)
void GeneratePermutationForUniqueString(string& gener_str, int str_size)
{
    if (str_size == 1)
    { //permutation is generated
        cout << gener_str << endl;
        return;
    }

    for (int i = 0; i < str_size; ++i)
    {                                                                //each character of string is a seed, i.e. parent of recursion stack
        GeneratePermutationForUniqueString(gener_str, str_size - 1); //decrease string size by 1

        if (i < str_size - 1)
        { //avoid additional swap
            if (!(str_size % 2))
                swap(gener_str[i], gener_str[str_size - 1]); //if string size is even then permute ith and last character
            else
                swap(gener_str[0], gener_str[str_size - 1]); //if string size is odd then permute first and last character
        }
    }
}

//simplest way to solve the problem with STL
void GeneratePermutationForUniqueStringSTL(string& gener_str, int str_size)
{
    do
    {
        cout << gener_str << endl;
    } while (next_permutation(gener_str.begin(), gener_str.end()));
}
