// Function to detect cycle in a directed graph.
    
    void bfs(vector<int>adj[],vector<int>&indegree,queue<int>&q,vector<int>&ans)
    {
        //vpn
        while(!q.empty())
        {
            //visite
            int node = q.front(); q.pop();
            //print
            ans.push_back(node);
            for(int nbr : adj[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>indegree(V,0);
        vector<int>topo;
        queue<int>q;
        
        for(int i=0;i<V;i++)
        {
            for(int nbr : adj[i])
            {
                indegree[nbr]++;
            }
        }
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        bfs(adj,indegree,q,topo);
        // cout<<topo.size()<<"\n";
        
        // if topo size is not equal then cycle is present 
        // thats why all nodes are not covered
        return topo.size() != V;
    }
