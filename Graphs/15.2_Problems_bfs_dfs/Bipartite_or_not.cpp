
bool dfs(int node,vector<int>adj[],vector<int>&color,int col)
    {
        color[node] = col;
        
        for(int nbr : adj[node])
        {
            if(color[nbr] == -1)
            {
                if(dfs(nbr,adj,color,!col)==false)
                    return false;
            }
            // visited and col !=
            else if(color[nbr] == col)
                return false;
        }
        return true;
    }

    bool bfs(vector<int>adj[] , int start,vector<int>&color)
    {
        int col;
        queue<int>q;
        q.push(start);
        while(!q.empty())
        {
            int node = q.front();
            int col = color[node]; //
            col = col ^ 1;
            q.pop();
            
            for(int nbr : adj[node])
            {
                // unvisited
                if(color[nbr]==-1)
                {
                    color[nbr] = col;//
                    q.push(nbr);
                }// visited and nbr col = node col then not bipartite graph
                else if(color[nbr]==color[node])
                {
                    return false;
                }
            }
            
        }
        return true;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	   for(int i=0;i<V;i++)
	   {
	       if(color[i]==-1)// if unvisited
	       {
	            color[i] = 0;
	          if(dfs(i,adj,color,0)== false)return false;
           // if(bfs(adj,i,color)== false)return false;
	       }
	   }
	   return true;
	}
