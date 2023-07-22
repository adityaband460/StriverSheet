class DisjointSet{
    public:
    vector<int>parent,rank;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int u)
    {
        if(parent[u]==u) return u;
        
        return parent[u] = findUParent(parent[u]);
    }
    void unionbyrank(int u,int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);
        
        if(pu==pv) return;
        if(rank[pu] < rank[pv])
        {
            parent[pu] = pv; 
        }
        else if(rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv; 
            rank[pv]++;
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        vector<int>ans;
        DisjointSet ds(n*m);
        vector<int>vis(n*m,0);
        
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            int node = row * m + col;
            
            // if(vis[node]==1) continue;
            
            vis[node]=1;
            for(int i=0;i<4;i++)
            {
                int nrow = row+dx[i];
                int ncol = col+dy[i];
                int nbr = nrow * m + ncol;
                if(nrow >=0 && nrow < n && ncol >=0 && ncol<m &&
                vis[nbr]==1)
                {
                    //insert edge node->nbr in disjoint set
                    if(ds.findUParent(node) != ds.findUParent(nbr))
                    {
                        ds.unionbyrank(node,nbr);
                    }
                }
                
            }
            
            // count visited && ultimate parents
            int cnt = 0;
            for(int i=0;i<n*m;i++)
            {
                if(vis[i]==1 && ds.parent[i]==i)
                {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
