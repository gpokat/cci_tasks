//Sorted Search, No Size: You are given an array-like data structure Listy which lacks a size
//method. It does, however, have an elementAt(i) method that returns the element at index i in
//0(1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data
//structure only supports positive integers.) Given a Listy which contains sorted, positive integers,
//find the index at which an element x occurs. If x occurs multiple times, you may return any index.


//Basically using binary search for solve the problem. The size of Listy could be counted for O(log(N)) time
//using double growing like n=2^k => k=log2(N).

//So, the runtime is O(2*log(N)), space is O(1) except recursive stack size.

int binarySearch(Listy list, int l, int r, int v) //classic BinarySearch
{
    if (r > l)
    {
        mid = l + (r - l) / 2;
        if (elementAt(mid) == v)
        {
            return mid;
        }

        if (elementAt(mid) > v)
        {
            return binarySearch(list, l, mid - 1, v);
        }
        return binarySearch(list, mid + 1, r, v);
    }
    return -1;
}

int BinarySearchWitoutSize(Listy list, int value) //log2(N) or log(N) size count method
{

    int index = 1;

    while (list.elementAt(index - 1) > 0 && list.elementAt(index - 1) < value)
    {
        index *= 2;
    }

    return binarySearch(list, 0, index, value);
}
