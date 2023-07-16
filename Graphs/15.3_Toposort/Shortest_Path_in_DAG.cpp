vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //create graph adj list
        vector<pair<int,int>>adj[N];
        
        // for all M edges
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        // intialize dist array
        vector<int>dist(N,1e9);
        dist[0] = 0; //src dist as 0
        // toposort both can be done dfs+stack or bfs+ indegree
        
        //bfs kahn's algo indegree
        
        queue<int>q;
        vector<int>indegree(N,0);
        vector<int>topo;
        for(int i=0;i<N;i++)
        {
            for(auto it : adj[i])
            {
                int v = it.first;
                indegree[v]++;
            }
        }
        for(int i=0;i<N;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // cout<<node<<" ";
            for(pair<int,int> nbr : adj[node])
            {
                int v = nbr.first;
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
            
        }
        // go 1 by 1 in topo sort nodes
        // relax each edge : set dist of their neighbours
        for(int i = 0; i < N; i++)
        {
            int u = topo[i];
            for(pair<int,int> nbr : adj[u])
            {
                int v = nbr.first;
                int wt = nbr.second;
                dist[v] = min(dist[v],dist[u]+wt);
                // cout<<"dist of "<<v<<" is "<<dist[v]<<" ";
            }
            
        }
        
        // convert dist of 1e9 to -1 : unreachable nodes
        
        for(int i=0;i<N;i++)
        {
            if(dist[i] >= 1e9)
                dist[i] = -1;
        }
        return dist;
    }
