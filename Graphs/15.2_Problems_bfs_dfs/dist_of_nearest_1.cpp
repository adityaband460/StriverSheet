void bfs(vector<vector<int>>&grid,vector<vector<int>>&vis,
    vector<vector<int>>&dist,queue<pair<pair<int,int>,int>> &q)
    {
       int m = grid.size(),n = grid[0].size();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1 ,0, -1, 0};
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int pdist = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                int dst = pdist+1;
                
                if(nrow >=0 && nrow <m && ncol >=0 && ncol <n &&
                vis[nrow][ncol]==0 && grid[nrow][ncol]==0)
                {
                    vis[nrow][ncol]= 1;
                    dist[nrow][ncol] = dst;
                    q.push({{nrow,ncol},dst});
                }
            }
        }
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	   int m = grid.size(),n = grid[0].size();
	   vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dist(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        bfs(grid,vis,dist,q);
        return dist;
	}
