//Sorted Matrix Search: Given an MxN matrix in which each row and each column is sorted in
//ascending order, write a method to find an element.

//The basice naive approach is to using binary search for each row of matrix to find an element.
//It's suitable due to rows and columns are sorted. So, it's give us an O(M*log(N)) runtime complexity
//with O(1) space.

//But the efficient way is to using heuristic greedy search approach to achive less runtime complexity.
//Since it 2D arry wich sorted in both directions it's give us a correlation between rows&columns.
//That mean we could take into accout diagonal elemnts to parse matrix faster for O(M+N) runtime.

pair<int, int> SearchInSortedMatrix(vector<vector<int>> &matrix, int value)
{

    int M = matrix.size();    //rows
    int N = matrix[0].size(); //columns

    int row = 0;     // begin with 1st row
    int col = N - 1; //begin with last column

    while (row < M && col >= 0)
    {

        if (matrix[row][col] == value)
        {
            return make_pair(row, col);
        }

        if (matrix[row][col] > value)
        {
            col--;
        }
        else
        {
            row++;
        }

        return make_pair(-1, -1);
    }
}
