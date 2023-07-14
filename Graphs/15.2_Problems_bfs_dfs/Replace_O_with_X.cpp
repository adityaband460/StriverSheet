// same as connected components
    // find connected components that include boundary nodes
    // bfs and dfs both will work
    
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& mat)
    {
        vis[row][col] = 1;
        
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            
            if(nrow >=0 && nrow <m && ncol >=0 && ncol <n 
            && vis[nrow][ncol]==0 && mat[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,vis,mat);
            }
        }
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // n X m
        vector<vector<int>>vis(n,vector<int>(m,0));
        // find boundary O's and call dfs on each of them
       
        for(int j=0;j<m;j++)
        {
             //top boundary
            if(mat[0][j] == 'O' && vis[0][j]== 0)
            {
                dfs(0,j,vis,mat);
            }
             // bottom boundary
            if(mat[n-1][j] == 'O' && vis[n-1][j]== 0)
            {
                dfs(n-1,j,vis,mat);
            }
        }
        for(int i=0;i<n;i++)
        {
            // left
            if(mat[i][0] == 'O' && vis[i][0]== 0)
            {
                dfs(i,0,vis,mat);
            }
             //right
            if(mat[i][m-1] == 'O' && vis[i][m-1]== 0)
            {
                dfs(i,m-1,vis,mat);
            }
        }
        // if vis = 0 then o will be replaced by x
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] == 0 && mat[i][j]=='O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
