//Permutations with Duplicates: Write a method to compute all permutations of a string whose
//characters are not necessarily unique. The list of permutations should not have duplicates.

//heap algortihm for generation permutations
//fast, elegant and simple implemet(like a weaving but more complex to understand)!
//The idea is to generate call stacks for each of character then permute elements dependence of position&number of stack count.
//The runtime is O(N*N!), space is O(N!/Dups!)
//The same approach that for unique string but witn additional space to collect unique permutations (set container used).
void GeneratePermutationForUniqueString(string& gener_str, int str_size, set<string>& store)
{
    if (str_size == 1)
    { //permutation is generated
        //if (!store.contains(gener_str)) //C++20
        if (!store.count(gener_str)) { //store unique permutations
            cout << gener_str << endl;
            store.insert(gener_str);
        }
        return;
    }

    for (int i = 0; i < str_size; ++i) { //each character of string is a seed, i.e. parent of recursion stack

        GeneratePermutationForUniqueString(gener_str, str_size - 1, store); //decrease string size by 1

        if (i<str_size-1) {// avoid additional unnecessary swap
            if (!(str_size % 2))
                swap(gener_str[i], gener_str[str_size - 1]); //if string size is even then permute ith and last character
            else
                swap(gener_str[0], gener_str[str_size - 1]); //if string size is odd then permute first and last character
        }
    }
}

//simplest way to solve the problem with STL
void GeneratePermutationForUniqueStringSTL(string gener_str, int str_size, set<string> &store)
{
    sort(gener_str.begin(), gener_str.end()); //make sort in alphabetical order
    do
    {
        //if (!store.contains(gener_str)) //C++20
        if (!store.count(gener_str)) //store unique permutations
        {
            cout << gener_str << endl;
            store.insert(gener_str);
        }
    } while (next_permutation(gener_str.begin(), gener_str.end()));
}
