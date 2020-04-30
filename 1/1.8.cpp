//Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
//column are set to O.


//Scan a MxN matrix for O(MxN) runtime,
//memorize ij indices and than set to 0
//row/col of matrix using by ij pair for O(MxN) at worst.
void ZeroMatrix(vector<vector<int>> MxN)
{

    int M = MxN.size();
    int N = MxN[0].size();

    vector<pair<int, int>> memory;
    memory.reserve(M * N);

  //a little bit redundancy in this design
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!MxN[i][j])
            {
                memory.emplace_back(i, j);
            }
        }
    }

    for (auto v : memory)
    {

        int i_ind = v.first;
        int j_ind = v.second;

        for (int i = 0; i < M; ++i)
        {
            MxN[i][j_ind] = 0;
        }

        for (int j = 0; j < N; ++j)
        {
            MxN[i_ind][j] = 0;
        }
    }
}
//p.s. It seems to be easy set to zero whole matrix with one command,
//coz the condition of task isn't correct (not complitely). That is why
//at first I must go to the answers and check requariments  - 'I shoud avoid recursive which 'zeroing' all elements' !!