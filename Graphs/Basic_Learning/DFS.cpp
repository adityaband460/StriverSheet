// Actual dfs code 
void dfs(vector<int>adj[],vector<int>&visited,int node,vector<int>&ans)
{
    visited[node] = 1;
    ans.push_back(node);

    for(int nbr : adj[node])
    {
        if(visited[nbr] == 0)
        {
            dfs(adj,visited,nbr,ans);
        }
    }
}
// Over thats it
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
   // convert edges list in to adjacency list
    vector<int> adjList[V];
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    // // to get DFS in Sorted (in level)
    // for(int i=0;i<V;i++)
    // {
    //     sort(adjList[i].begin(),adjList[i].end());
    // }
    //  to cover disconnected components code
    vector<int>visited(V,0);
    vector<vector<int>>ans;
     
    for(int i=0;i<V;i++) // to cover disconnected components
    {
        if(visited[i]== 0)
        {
            vector<int>subans;
            dfs(adjList,visited,i,subans);
            ans.push_back(subans);
        }
    }
   
    return ans;

}
