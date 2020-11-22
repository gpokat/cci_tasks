//Peaks and Valleys: In an array of integers, a "peak" is an element which is greater than or equal
//to the adjacent integers and a "valley" is an element which is less than or equal to the adjacent
//integers. For example, in the array {5, 8, 6, 2, 3, 4, 6 }, {8, 6} are peaks and {5, 2} are valleys. Given an
//array of integers, sort the array into an alternating sequence of peaks and valleys.
//EXAMPLE
//Input: {5, 3, 1,2, 3}
//Output: {5, 1,3 ,2, 3}

//The simple and obviouse way to solve this problem is to sort array in inscresing order and
//just swap adjacent elements.

//The more efficient way is to use some heuristic which based on swapping techniques.
//The runtime is O(N) insted of prevouse O(N*log(N)) and space O(1).

//This approach based on local order i.e. for abc if a>b & b>c then a>c for the even indexes.
//It's work for array withot duplicates. it's look like 'open local triangle'

void SortAsWave(vector<int> &arr)
{
    int N = arr.size();

    // Traverse all even elements
    for (int i = 0; i < N; i += 2)
    {
        // If current even element is smaller than previous
        if (i > 0 && arr[i - 1] > arr[i]) //check leftside
            swap(arr[i], arr[i - 1]);

        // If current even element is smaller than next
        if (i < N - 1 && arr[i] < arr[i + 1]) //check rightside
            swap(arr[i], arr[i + 1]);
    }
}