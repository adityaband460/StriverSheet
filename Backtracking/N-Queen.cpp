class Solution {
public:

    void solve(int row,
               int n,
               vector<string>& board,
               vector<int>& col,
               vector<int>& diag1,
               vector<int>& diag2,
               vector<vector<string>>& ans)
    {
        // All queens placed
        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++)
        {
            int d1 = row - c + n - 1;
            int d2 = row + c;

            // Check whether this position is safe
            if (col[c] || diag1[d1] || diag2[d2])
                continue;

            // Choose
            board[row][c] = 'Q';
            col[c] = 1;
            diag1[d1] = 1;
            diag2[d2] = 1;

            // Explore
            solve(row + 1, n, board, col, diag1, diag2, ans);

            // Undo
            board[row][c] = '.';
            col[c] = 0;
            diag1[d1] = 0;
            diag2[d2] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        vector<int> col(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);

        solve(0, n, board, col, diag1, diag2, ans);

        return ans;
    }
};
