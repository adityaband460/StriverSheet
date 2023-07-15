vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int>adj[n] ;
        vector<int>indegree(n,0);
        //convert into graph
        for(int i=0;i<m;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //fill indegree's
        for(int i=0;i<n;i++)
        {
            for(int nbr : adj[i])
            {
                indegree[nbr]++;
            }
        }
        // do kahn's bfs topo sort
        
        queue<int>q;
        vector<int>topoSortSeq;
        
        // set up queue with 0 in-degree vertices
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front(); q.pop();
            topoSortSeq.push_back(node);
            
            for(int nbr : adj[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
        }
        if(topoSortSeq.size() != n)// size != no of vertices,
        { // no topo sort possible
            return {};
        }
        else
        {
            return topoSortSeq;
        }
    }
