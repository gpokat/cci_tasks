//Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
//bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

//In-place method to rotate matrix by 90 degree.
//Based on backward swaps of elements of input matrix using by recurrent expression according to the square rotation.
//Runtime complexity lower than O(n+n*log(n)) approximately, space complexity is O(1).
//Could be optimize more by using SSE/AVX
void RotateMatrixBy90Degree(vector<vector<int>> NxN)
{

    int N = NxN[0].size(); //sizeof(NxN) / sizeof(NxN[0]);
    int Nj = N - 1;
    int Ni = ceil(N / 2);
    int j = 1;

    for (int i = 1; i <= Ni; ++i)
    {
        for (; j <= Nj; j++)
        {
            swap(NxN[i - 1][j - 1], NxN[N - j][i - 1]);
            swap(NxN[N - j][i - 1], NxN[N - i][N - j]);
            swap(NxN[N - i][N - j], NxN[j - 1][N - i]);
        }
        j = i + 1;
        Nj -= 1;
    }
}
