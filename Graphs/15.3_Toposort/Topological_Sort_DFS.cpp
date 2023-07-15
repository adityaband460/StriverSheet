void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
	    vis[node] = 1;
	    
	    for(int nbr : adj[node])
	    {
	        if(vis[nbr]==0)
	        {
	            dfs(nbr,adj,vis,st);
	        }
	    }
	    // my all neighbours are in stack
	    // I am pre requisite for them so I am goint at top of them
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>vis(V,0);
	    stack<int>st;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	            dfs(i,adj,vis,st);
	        }
	    }
	    vector<int>topoSortedOrder;
	    while(!st.empty())
	    {
	        topoSortedOrder.push_back(st.top());
	        st.pop();
	    }
	    return topoSortedOrder;
	}
