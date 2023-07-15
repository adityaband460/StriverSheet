bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<int> adj[])
    {
        // vpn
        vis[node]= 1;
        pathvis[node]=1;
        
        for(int nbr : adj[node])
        {
            if(vis[nbr]==0)
            {
                if(dfs(nbr,vis,pathvis,adj) == true) return true;
            }
            // else if(par != nbr) return false;  undirected graph
            else if(pathvis[nbr]==1 )
            {
                return true;
            }
            
        }
        // unmark node from path
        pathvis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,vis,pathvis,adj)==true)return true;
            }
        }
        return false;
    }
