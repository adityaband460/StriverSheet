//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        
        vector<int>dist(V,1e9);
        dist[S]=0;
        pq.push({0,S});
        
        // same as bfs just used priority queue
        // using queue will also work but it will increase
        // time complexity by a lot.
        while(!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            //for all neighbours
            for(vector<int> nbr : adj[node])
            {
                int v = nbr[0];
                // cout<<v<<" ";
                int wt =nbr[1];
                // cout<<wt<<" ";
                if(dist[v] > dist[node] + wt)
                {
                    dist[v]= dist[node]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
