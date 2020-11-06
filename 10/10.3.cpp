//Search in Rotated Array: Given a sorted array of n integers that has been rotated an unknown
//number of times, write code to find an element in the array. You may assume that the array was
//originally sorted in increasing order.
//EXAMPLE
///InputfindSin { 15, 16, 19, 20, 25, 1, 3,4,5,7,10, 14 }
//Output 8 (the index of 5 in the array)

//Basic idea is to using a BinarySearch algorithm to find a key, becouse a parts of array
//is sorted and after dividing the whole array by parts finally it give us a sub-sorted arrays
//which suitable for BinarySort.

//The runtime is O(log(N)) for unique array, O(N) for arr with duplicates which equave to using just for loop.
//The space is O(1).


vector<int> test = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

int MultiStageBinarySearch(vector<int> &arr, int l, int r, int key)
{

    if (r > l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] > arr[l])
        { // left part of arr normalized

            if (arr[mid] > key && arr[l] <= key)
            {
                return MultiStageBinarySearch(arr, l, mid - 1, key);
            }
            else
            {
                return MultiStageBinarySearch(arr, mid + 1, r, key);
            }
        }
        else if (arr[mid] < arr[l])
        { //right part of arr normalized

            if (arr[mid] < key && arr[r] >= key)
            {
                return MultiStageBinarySearch(arr, mid + 1, r, key);
            }
            else
            {
                return MultiStageBinarySearch(arr, l, mid - 1, key);
            }
        }
        else if (arr[l] == arr[mid])
        { //edge case with duplicates
            if (arr[mid] != arr[r])
            { //check right part of arr if it's different
                return MultiStageBinarySearch(arr, mid + 1, r, key);
            }
            else
            {
                int key_index = MultiStageBinarySearch(arr, l, mid - 1, key);
                if (key_index < 0)
                    key_index = MultiStageBinarySearch(arr, mid + 1, r, key);

                return key_index;
            }
        }
    }
    return -1;
}
