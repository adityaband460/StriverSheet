// no of enclaves using bfs
    void bfs(vector<vector<int>> &grid,vector<vector<int>> &vis,
    queue<pair<int,int>>&q)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                
                if(nrow >=0 && nrow<n && ncol >=0 && ncol <m
                && grid[nrow][ncol]==1 && vis[nrow][ncol]==0)
                {
                    // cout<<nrow<<" "<<ncol<<"\n";
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j== 0 || j==m-1)// boundary nodes
                {
                    if(grid[i][j]==1)
                    {
                        // cout<<i<<" "<<j<<" \n";
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                    
                }
            }
        }
        bfs(grid,vis,q);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]== 0 && grid[i][j]==1)
                cnt++;
            }
        }
        return cnt;
    }
