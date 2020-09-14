//Eight Queens: Write an algorithm to print all ways of arranging eight queens on an 8x8 chess board
//so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all
//diagonals, not just the two that bisect the board.

//To solve this problem using simple brute-force with backtrack strategy. To avoid uneccesary calculations add some heuristic rules.
//This approach called greedy strategy(brute-force+backtrack+heuristic)
//Heuristic rules apply for the queen position on the rows, cols and diagonals on the chess board.

//Naive solution w/o any optimizations.
//Approximately imeprical runtume is O(2*N!), space is O(2*N^2) due to additional buffers.
//Finally it is made 5602712 iterations to find all 92 unique solution.
//The approach could be extrimely optimized to modified cover function, avoid store additional buffers, slow find vector functions and compile optimization (-03 up to 10 times).

const int bsize = 8;
static vector<vector<int>> board(bsize, vector<int>(8, 0));  //empty chess board
static vector<vector<int>> tboard(bsize, vector<int>(8, 0)); //empty chess board

//native heuristics rules
void cover(int ii, int jj, int value)
{

    int ipos = ii;
    int jpos = jj;

    //cover hotizontal line
    for (int j = 0; j < bsize; ++j)
    {
        if (board[ipos][j] == 0)
            board[ipos][j] = value;
        else if (board[ipos][j] == value)
            board[ipos][j] = 0;
    }
    //cover vertical line
    for (int i = 0; i < bsize; ++i)
    {

        if (board[i][jpos] == 0)
            board[i][jpos] = value;
        else if (board[i][jpos] == value)
            board[i][jpos] = 0;
    }

    //diagonal part-covering
    while (ipos > 0 && jpos > 0)
    {
        ipos--;
        jpos--;
        if (board[ipos][jpos] == 0)
            board[ipos][jpos] = value;
        else if (board[ipos][jpos] == value)
            board[ipos][jpos] = 0;
    }

    ipos = ii;
    jpos = jj;
    while (ipos < bsize - 1 && jpos < bsize - 1)
    {

        ipos++;
        jpos++;
        if (board[ipos][jpos] == 0)
            board[ipos][jpos] = value;
        else if (board[ipos][jpos] == value)
            board[ipos][jpos] = 0;
    }

    ipos = ii;
    jpos = jj;
    while (ipos > 0 && jpos < bsize - 1)
    {
        ipos--;
        jpos++;
        if (board[ipos][jpos] == 0)
            board[ipos][jpos] = value;
        else if (board[ipos][jpos] == value)
            board[ipos][jpos] = 0;
    }
    ipos = ii;
    jpos = jj;
    while (ipos < bsize - 1 && jpos > 0)
    {
        ipos++;
        jpos--;

        if (board[ipos][jpos] == 0)
            board[ipos][jpos] = value;
        else if (board[ipos][jpos] == value)
            board[ipos][jpos] = 0;
    }

    //queen-place cover
    if (board[ii][jj] == 0)
        board[ii][jj] = value;
    else if (board[ii][jj] == value)
        board[ii][jj] = 0;
}

static vector<pair<int, int>> queenSets;         //current solution
static vector<vector<vector<int>>> queenSetsSOL; //store unique solutions

//static int iter = 0;
//static int sol = 0;
void SetQueen(int row, int col)
{

    //    iter++;

    //set queen to place and apply heurictic
    queenSets.push_back(make_pair(row, col));
    cover(row, col, queenSets.size());

    if (queenSets.size() == bsize) //if solution is found
    {

        vector<int> evec(8, 0);
        tboard = {evec, evec, evec, evec, evec, evec, evec, evec};

        //fill solution board
        for (int i = 0; i < bsize; ++i)
        {
            for (int j = 0; j < bsize; ++j)
            {
                if (find(queenSets.begin(), queenSets.end(), make_pair(i, j)) != queenSets.end())
                    tboard[i][j] = 1;
            }
        }

        //check if the store has solution in the bank store
        if (find(queenSetsSOL.begin(), queenSetsSOL.end(), tboard) != queenSetsSOL.end())
        {
            //do backtrack
            cover(queenSets.back().first, queenSets.back().second, queenSets.size());
            queenSets.pop_back();
            return;
        }

        //if solution is unique then push it to store
        queenSetsSOL.push_back(tboard);

        //    sol++;
    }

    //if backtrack return to zero-state board that mean all of the possible state checked
    //then return
    if (queenSets.size() == 0)
    {
        return;
    }

    //trying place queen to the free cell of the board
    for (int i = 0; i < bsize; ++i)
    {
        for (int j = 0; j < bsize; ++j)
        {
            if (!board[i][j])
            {
                SetQueen(i, j);
            }
        }
    }

    //backtrack if board full but solution didin't find
    cover(queenSets.back().first, queenSets.back().second, queenSets.size());
    queenSets.pop_back();

    return;
}

int main()
{

    vector<int> evec(8, 0);

    for (int j = 0; j < bsize; ++j)
    {
        queenSets.clear();
        board = {evec, evec, evec, evec, evec, evec, evec, evec};
        tboard = {evec, evec, evec, evec, evec, evec, evec, evec};

        SetQueen(0, j);
    }
    /*
    for (auto sol : queenSetsSOL)
    {

        for (int i = 0; i < bsize; ++i)
        {
            for (int j = 0; j < bsize; ++j)
            {

                cout << sol[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    cout << "f: " << queenSetsSOL.size() << "," << iter << endl; */
}