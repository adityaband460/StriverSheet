vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
  // convert edges list in to adjacency list
    vector<int> adjList[vertex];
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    // to get BFS in Sorted (in level)
    for(int i=0;i<vertex;i++)
    {
        sort(adjList[i].begin(),adjList[i].end());
    }
    // Actual code
    vector<int> ans;
    vector<bool>visited(vertex,0);
    queue<int>q;
   
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
        {
            q.push(i);
            visited[i] = true;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(int nbr : adjList[node])
                {
                    if(!visited[nbr])
                    {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
        }
    }
    return ans;
}
