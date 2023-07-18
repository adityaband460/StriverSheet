int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
       
       // Dijkstra algo :similar to normal BFS only as all dist are same (1)
       // just edge wts are added
       int n = grid.size();
       int m = grid[0].size();
       queue<pair<int,int>>q;
       vector<vector<int>>dist(n,vector<int>(m,1e9));
       
       q.push(source);
       dist[source.first][source.second]=0;
       
       int dx[] = {0,1,0,-1};
       int dy[] = {1,0,-1,0};
       while(!q.empty())
       {
           pair<int,int> it = q.front();q.pop();
           int row = it.first;
           int col = it.second;

           //boundary , grid==1 ,not visited ie. dist is more than v+wt
           for(int i=0;i<4;i++)
           {
               int nrow = row+dx[i];
               int ncol = col + dy[i];
               
               int altdist = dist[row][col]+1;
               if(nrow >=0 && nrow <n && ncol >=0 && ncol <m
               && grid[nrow][ncol]==1 && dist[nrow][ncol]>altdist)
               {
                   dist[nrow][ncol]=altdist;
                   q.push({nrow,ncol});
               }
           }
       }
       for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(dist[i][j] >= 1e9)
                dist[i][j] = -1;
        }
       
       return dist[destination.first][destination.second];
    }
