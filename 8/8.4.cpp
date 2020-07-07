//Power Set: Write a method to return all subsets of a set.

//The idea is to use backtrack approach to reduce redundant recursive calls.
//The runtime is O(2^N), space is O(N) roughly due to store new_set vector
void GeneratePossibleSets(vector<int> &input_set, vector<int> &new_set, vector<vector<int>> &sets, int start_idx = -1)
{

    if (new_set.size() == input_set.size())
        return; //if generated initial set then go out from recursion i.e. back to for-loop below

    if (new_set.size() > 0)
        sets.push_back(new_set);

    for (int i = start_idx + 1; i < input_set.size(); ++i)
    {
        new_set.push_back(input_set[i]);
        GeneratePossibleSets(input_set, new_set, sets, i);

        //point out from recursion stack
        new_set.pop_back(); //remove last element in generated set (a I part of backtrack)
    }

    return; //if for-loop processed all input_set trought stack do II part of backtrack
}

vector<vector<int>> GeneratePossibleSets(vector<int> &input_set)
{
    vector<vector<int>> sets;
    vector<int> tmp;
    GeneratePossibleSets(input_set, tmp, sets);
    return sets;
}