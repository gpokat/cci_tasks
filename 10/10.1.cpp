//Sorted Merge: You are given two sorted arrays, A and B, where A has a large enough buffer at the
//end to hold B. Write a method to merge B into A in sorted order.


//Starting with end of the first array (last existing element), compare with last element from second array due to the arrays already sorted,
//it give us the largest element between both arrays then placing it elemtn to the end of the first array (empty slot).
//And just cover indices.
//The runtime is O(M+N), space is O(1)

void MergeArraysWithSort(vector<int> &A, vector<int> &B)
{

    int i = A.size() - 1;
    int j = B.size() - 1;

    int k = A.size() + B.size() - 1;

    while (j >= 0)
    {

        if (i >= 0 && A[i] > B[j])
        {
            A[k] = A[i];
            i--;
        }
        else
        {
            A[k] = B[j];
            j--;
        }
        k--;
    }
}
