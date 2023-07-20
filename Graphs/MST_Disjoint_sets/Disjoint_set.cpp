#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank, parent, size;
public :
    DisjointSet(int n)
    {   // to support 1 based indexing as well
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    //using path compression
    int findUltimateParent(int u)
    {
        if(parent[u]==u)
        {
            return u;
        }
        return parent[u] = findUltimateParent(parent[u]);
    }
// use any one of union b yrank or union by size
    void unionByRank(int u ,int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        
        if(pu == pv) return; // they are already connected
        
        if(rank[pu] < rank[pv])
        {
            parent[pu]= pv;
        }
        else if(rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else // their ranks are equal
        {
            parent[pu] = pv;
            rank[pu]++;
        }
    }
    void unionBySize(int u ,int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        
        if(pu == pv) return; // they are already connected
        
        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
