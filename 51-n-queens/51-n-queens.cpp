class Solution
{
public:
    bool check(vector<string> &board, int c, int r)
    {

        // up

        int u = r;
        while (u >= 0)
        {
            if (board[u][c] == 'Q')
                return 0;

            u--;
        }

        // ldiag

        u = r;
        int l = c;

        while (u >= 0 && l >= 0)
        {
            if (board[u][l] == 'Q')
                return 0;
            u--;
            l--;
        }

        // rdiag

        u = r;
        int ri = c;

        while (u >= 0 && ri <= board[0].size() - 1)
        {

            if (board[u][ri] == 'Q')
                return 0;

            u--;
            ri++;
        }

        return 1;
    }

    void nqueen(vector<vector<string>> &ans, vector<string> &board, int c, int r)
    {

        if (c == board[0].size())
            return;

        if (r == board.size())
        {
            ans.push_back(board);
            return;
        }

        if (check(board, c, r))
        {
            board[r][c] = 'Q';
            nqueen(ans, board, 0, r + 1);
            board[r][c] = '.';
        }

        nqueen(ans, board, c + 1, r);
    }

    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> ans;
        vector<string> board(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i].push_back('.');
            }
        }

        nqueen(ans, board, 0, 0);

        return ans;
    }
};