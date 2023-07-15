	//vpn
	void bfs(vector<int> adj[],vector<int>&indegree,queue<int>&q,vector<int>&ans)
	{
	    while(!q.empty())
	    {
	        // visit
	        int node = q.front(); q.pop();
	        //print
	        ans.push_back(node);
	        //remove node with in-degree 0 
	        // so nodes which are neighbours to node will get their
	        // indegree reduced
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
	
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(int nbr : adj[i])
	        {
	            indegree[nbr]++;
	        }
	    }
	    queue<int>q;
	    vector<int>topoSortedOrder;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    
	    bfs(adj,indegree,q,topoSortedOrder);
	    return topoSortedOrder;
	}
