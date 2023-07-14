void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis,
    vector<pair<int,int>>&v,int baserow,int basecol)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        v.push_back({row-baserow,col-basecol});
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int nrow = row+dx[i];
            int ncol = col+dy[i];
            
            if(nrow>=0 && nrow<n && ncol >=0 && ncol<m
            && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,grid,vis,v,baserow,basecol);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>>s;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               vector<pair<int,int>>v;
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    dfs(i,j,grid,vis,v,i,j);
                    s.insert(v);
                }
            }
        }

        return s.size();
    }
