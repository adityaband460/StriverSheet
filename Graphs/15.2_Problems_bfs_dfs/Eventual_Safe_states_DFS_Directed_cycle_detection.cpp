 bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathvis)
    {
        vis[node]=1;
        pathvis[node]=1;
        
        for(int nbr : adj[node])
        {
            if(vis[nbr]==0)
            {
               if(dfs(nbr,adj,vis,pathvis)==true) return true;
            }
            else if(pathvis[nbr]==1)
            {
                return true; // nodes in cycle will not go below this line
                // hence then can't reset the path vis;
            }
        }
        pathvis[node]= 0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,adj,vis,pathvis);
            }
        }
        vector<int>safeNodes;
        for(int i=0;i<V;i++)
        {
            if(pathvis[i]==0)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
