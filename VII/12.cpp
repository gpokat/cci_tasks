//The answer is O(b*log(b)+a*log(b)).
//The final complexity is consist of two undependent blocks:
// 1 - mergesort, 2 - loop for with binarySearch.
//Thats why we should summarize they, but
//have to multiply loop and binarySearch complexity, coz they depend of each other.

int intersection(int *a, int *b)
{
    mergesort(b); //O(b*log(b))
    int intersect = 0;

    for (auto x : a) //O(a)
    {
        if (binarySearch(b, x) >= 0) //O(log(b))
        {
            intersect++;
        }
    }
    return intersect;
}