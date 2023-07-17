//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // set
        set<pair<int,int>>s;
        
        vector<int>dist(V,1e9);
        dist[S]=0;
        s.insert({0,S});
        
        while(!s.empty())
        {
            auto it = *(s.begin());
            s.erase(it);// deletion base on value
            int node = it.second;
            int dis =  it.first;
            for(vector<int> nbr : adj[node])
            {
                int v = nbr[0];
                int wt = nbr[1];
                
                if(dist[node]+wt < dist[v])
                {
                    // if it is modified by someone else
                    // remove that pair to avoid un necessory iterations
                    if(dist[v] != 1e9)
                    {
                        s.erase({dist[v],v});
                    }
                    dist [v] = dist[node]+wt;
                    s.insert({dist[v],v});
                }
            }
        }
        
        return dist;
    }
