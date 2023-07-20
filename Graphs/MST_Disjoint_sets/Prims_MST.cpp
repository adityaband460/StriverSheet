//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>visited(V,0);
        int sum = 0;
        
        // dist , node
        pq.push({0,0});
        
        // vpn : visited plus(sum) neighbours
        while(!pq.empty())
        {
            auto it = pq.top() ; pq.pop();
            int node = it.second;
            int wt = it.first;
            
            // here visited means it is present in mst
            if(visited[node]==0)
            {
                visited[node]=1;
                sum += wt;
                //neighbours
                for(auto nbr : adj[node])
                {
                    int v = nbr[0];
                    int wt = nbr[1];
                //if you might be part of mst as you are unvisited 
                    if(visited[v]==0)
                    {
                        pq.push({wt,v});
                    }
                }
            }
            else
            {
                // nothing
            }
        }
        return sum;
    }
