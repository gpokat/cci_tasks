//Magic Index: A magic index in an array A[0 ... n-1] is defined to be an index such that A[i]=i.
//Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.
//FOLLOW UP
//What if the values are not distinct?

//Simple approach for linear time O(N) is just a traverse trought array and check index with data.
//So, more fater approach based on binary search and it could be work for O(log(N)) runtime.
//With modification to cover non-distinct case aka left most
//The space is O(1)
int binary_search(int *arr, int left, int right)
{
    if (left > right)
        return -1; //if overlap then end

    int middle = (right + left) / 2; //or l+(r-l)/2 to avoid overflow
    if (arr[middle] == middle)
    {
        return middle;
    }

    //Follow up modification for take into account duplicated elements
    int leftmost = (arr[middle] < middle - 1) ? arr[middle] : middle - 1; //min between data & index
    int left_most_magic = binary_search(arr, left, leftmost);
    if (left_most_magic >= 0)
        return left_most_magic; //looking for left part of array

    //otherwise looking for right part of array
    int rightmost = (arr[middle] > middle + 1) ? arr[middle] : middle + 1; //max between data & index
    int right_most_magic = binary_search(arr, rightmost, right);
    return right_most_magic;
}

