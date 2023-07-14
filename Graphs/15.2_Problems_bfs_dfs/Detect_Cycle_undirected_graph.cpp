// both methods included
bool bfs(int node,int par,vector<int>&vis,vector<int>adj[])
    {
        queue<pair<int,int>>q;
        q.push({node,par});
        vis[node] = 1;
        
        while(!q.empty())
        {
            int vertex = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int nbr : adj[vertex])
            {
                if(vis[nbr] == 0)
                {
                    vis[nbr] = 1;
                    q.push({nbr,vertex});
                }
                else if(nbr != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int node,int par,vector<int>&vis,vector<int>adj[])
    {
        vis[node] = 1;
        
        for(int nbr : adj[node])
        {
            if(vis[nbr]==0)
            {
                if(dfs(nbr,node,vis,adj) == true)
                    return true;
            }
            else if(nbr != par)//alredy visited but its not parent
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
         for(int i=0;i<V;i++)
         {
             if(vis[i]==0)
             {
                 if(bfs(i,-1,vis,adj)==true) return true;
             }
         }
         return false;
    }
