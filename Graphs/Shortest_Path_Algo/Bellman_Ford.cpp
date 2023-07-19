/*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    
    // Time complexity : V x E
    // space : V
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
       
       // do relaxation V-1 times
       vector<int>dist(V,1e8);
       dist[S] = 0;
       
       for(int i=0;i<V-1;i++)
       {
           for(auto edge : edges) // for all edges
           {
               int u = edge[0];
               int v = edge[1];
               int wt = edge[2];
               
               // u should be reachable
               // relax edge uv
               if( dist[u] != 1e8 && dist[u]+ wt < dist[v])
               {
                   dist[v] = dist[u]+ wt;
               }
           }
       }
       bool cycle = false;
       // V th iteration
       for(auto edge : edges)
       {
           int u = edge[0];
           int v = edge[1];
           int wt = edge[2];
           
           if(dist[u] != 1e8 && dist[v] > dist[u]+ wt)
           {
               cycle = true;
               dist[v] = dist[u]+ wt;
           }
       }
        if(cycle)return {-1};
        else
            return dist;
    }
