int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<int>> adj[n];
        for(int i=0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            
            //bi-directional roads
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int src = 0,dest=n-1;
        //dist,node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<long long>dist(n,1e18);
        vector<int>times(n,0);
        
        times[src] = 1;
        //dist , node
        pq.push({0,src});
        dist[src]=0;
        
        while(!pq.empty())
        {
            auto it = pq.top();pq.pop();
            long long dis = it.first;
            int node = it.second;
            
            for(auto nbr : adj[node])
            {
                int v = nbr[0];
                int wt = nbr[1];
                
                if(dis+wt < dist[v])
                {
                    //  cout<<"node is "<<node<<" \n";
                    dist[v] = dis+wt;
                    pq.push({dist[v],v});
                    times[v] = (times[v] + times[node])%mod;
                }
                else if(dis + wt == dist[v])
                {
                    //  cout<<"node is did->"<<node<<" to "<<v<<" "<<times[v]+1<<" \n";
                    times[v] = (times[v] + times[node])%mod;
                }
            }
        }
        return times[dest];
        
    }
