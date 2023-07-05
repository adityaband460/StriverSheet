bool isSafe(vector<vector<int>>&board,int row,int col)
    {
        int n = board.size();
        int i = row,j=col;
       // upper diagonal
       
       while(i>=0 && j>=0)
       {
           if(board[i][j]==1)
            return false;
           i--;
           j--;
       }
       //left row
       i=row;
       j= col;
       while(j>=0)
       {
           if(board[i][j])
            return false;
           j--;
       }
       // down diagonal
        i=row;
        j= col;
       while(i<n && j>=0)
       {
           if(board[i][j])
            return false;
           i++;
           j--;
       }
       return true;
        
    }
    void nQ(vector<vector<int>>&ans,int col,vector<vector<int>>&board)
    {
        int n = board.size();
        if(col == n)
        {
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                for(int j=n-1;j>=0;j--)
                {
                    if(board[j][i] == 1)
                    {
                        temp.push_back(n-j);
                        break;
                    }
                }
            }
            ans.push_back(temp);
            return ;
        }
        
        
        //rec case
        for(int i=0;i<n;i++) // try all rows
        {
            if(isSafe(board,i,col))
            {
                board[i][col] = 1;
                nQ(ans,col+1,board);
                board[i][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<int>>ans;
        nQ(ans,0,board);
         sort(ans.begin(),ans.end());
        return ans;
    }
