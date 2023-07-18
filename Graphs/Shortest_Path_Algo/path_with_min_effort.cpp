int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        // diff , row, col
        priority_queue<pip,vector<pip>,greater<pip>>pq;
        // efforts
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int prevdiff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            
            int dx[] = {0,1,0,-1};
            int dy[] = {-1,0,1,0};
            
           for(int i=0;i<4;i++)
            {
                int nrow = row + dx[i];
                int ncol = col +dy[i];
                
                //boundary check
                if(nrow>=0 && nrow<n && ncol >=0 && ncol<m )
                {
                    // notice this
                    //////////////////////////////////////////////
                    int absdiff = abs(heights[row][col]-heights[nrow][ncol]);
                    int newEffort = max(prevdiff,absdiff);
                    if(newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                    
                }
            }
        }
        return dist[n-1][m-1];
    }
