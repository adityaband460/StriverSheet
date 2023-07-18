int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
       // convert edges into adj list 
       
       vector<vector<int>>adj[n];
       for(int i=0;i<flights.size();i++)
       {
           int u = flights[i][0];
           int v = flights[i][1];
           int wt = flights[i][2];
           
           adj[u].push_back({v,wt});
       }
       
        // dist,node
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,0}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
        
            int stops = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if(stops > K)
                break;
            for(auto nbr : adj[node])
            {
                int v = nbr[0];
                int wt = nbr[1];
                if( dist[v] > dis + wt)
                {
                    dist[v]= dis +wt;
                    q.push({stops+1,{v,dist[v]}});
                }
            }

        }
        if(dist[dst]==1e9)
            return -1;
        return dist[dst];
    }
