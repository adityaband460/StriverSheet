/*
 important edge cases :
  if we have 2 branches and 1st branche does not work out , perform back-traking till reset point,
  and go recrusive on 2nd branch.
*/
class Solution {
public:

    bool solve(int i, int j,int ind, vector<vector<int>>& vis,vector<vector<char>>& board, string &word)
    {
        int rows = board.size();
        int cols = board[0].size();

        //base cases 

        // 1) // if last char matches return true
        if(ind == word.size()) return true;


        // 2)if out of range, already vis it should return false
        if(i < 0 || i >=rows || j < 0 || j >= cols || (vis[i][j] == 1))
        {
            return false;
        }
                
        //3) // if curr char does not match ret false
        if(board[i][j] != word[ind]) return false;

        //rec case
        
        // mark it visited
        vis[i][j] = 1;
        
        // come till here means char matches but its
        // not last index so try all neightbours

        int x[] = {0,1,0,-1};
        int y[] = {1,0,-1,0,};

        // try all neighbours
        for(int k=0;k<4;k++)
        {
            if(solve(i+x[k],j+y[k],ind+1,vis,board,word) == true)
                return true;
        }

        // backtrack if current path doesn't work out
        vis[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> vis(rows,vector<int>(cols,0));
       

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
               if(solve(i,j,0,vis,board,word) == true) return true;    

               vis = vector<vector<int>>(rows,vector<int>(cols,0)); // to reset visited for next call
            }
        }
        return false;
    }
};
