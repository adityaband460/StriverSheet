class DisjointSet{
    vector<int>rank,par;
    public:
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            par.resize(n+1,0);
            for(int i=0;i<=n;i++)
            {
                par[i] = i;
            }
        }
    int findUParent(int u)
    {
        if(u==par[u])
            return u;
        return par[u] = findUParent(par[u]);
    }
    void unionByRank(int u,int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);
        
        if(rank[pu] < rank[pv])
        {
            par[pu] = pv;
        }
        else if(rank[pv] < rank[pu])
        {
            par[pv]= pu;
        }
        else
        {
            par[pu] = pv;
            //rank of par increases by 1
            rank[pv]++;
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Krushkal's algo
        vector<pair<int,pair<int,int>>>edgeList;
        
        for(int i=0;i<V;i++)
        {
            for(int nbr= 0;nbr<adj[i].size();nbr++)
            {
                int u = i;
                int v = adj[i][nbr][0];
                int wt = adj[i][nbr][1];
                edgeList.push_back({wt,{u,v}});
            }
           
        }
        
        //sort edges E logE
        sort(edgeList.begin(),edgeList.end());
        
        //disjoint set
        DisjointSet ds(V);
        int sum = 0;
        for(int i=0;i<edgeList.size();i++)
        {
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            int wt = edgeList[i].first;
            if(ds.findUParent(u) != ds.findUParent(v))
            {
                sum += wt;
                ds.unionByRank(u,v);
            }
        }
        return sum;
    }
};
