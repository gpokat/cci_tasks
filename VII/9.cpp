
//The answer is O(n1+n2+n3....+nN) => n^2/2 + n/2
//Simplify is  O(n^2)

//Method appendToNew iterates through array n times,
//that's why it should be at least n*n times.

//translate from Java to C++ using by STL vector container
vector<int> appendToNew(vector<int> array, int value)
{
    //cpy elements to new arr
    vector<int> bigger(array.size() + 1);

    for (int i = 0; i < array.size(); i++)
    {
        bigger[i] = array[i];
    }

    //add new elem
    bigger[bigger.size() - 1] = value;
    return bigger;
}

vector<int> copyArray(vector<int> array)
{
    vector<int> copy;

    for (auto value : array)
    {
        copy = appendToNew(copy, value);
    }

    return copy;
}
