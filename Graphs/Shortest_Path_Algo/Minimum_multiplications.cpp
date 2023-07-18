    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        // edge case
        if(start == end)
            return 0;
        // dijkstra with queue same as bfs
        // as steps will increase by +1 everytime
        
        // steps,node
        queue<pair<int,int>>q;
        vector<int>dist(1e5,1e9);// 1e5 vertices 0 - 9999
        
        q.push({0,start});
        dist[start] = 0;
        while(!q.empty())
        {
            auto it = q.front(); q.pop();
            int node = it.second;
            int steps = it.first;
            
            //neighbours
            for(int multiplier : arr)
            {
                int nbr = (node * multiplier) % static_cast<int>(1e5);
                
                if(nbr == end)
                    return steps+1;
                    
                if(steps + 1  < dist[nbr])
                {
                    dist[nbr]= steps+1;
                    q.push({dist[nbr],nbr});
                }
            }
        }
       
        return -1;
    }
