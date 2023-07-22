class DisjointSet{
    public:
    vector<int>par,rank;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            par[i] = i;
        }
    }
    int findUPar(int u)
    {
        if(u == par[u])
            return u;
        
        return par[u] = findUPar(par[u]);
    }
    void unionbyrank(int u,int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv)return;
        
        if(rank[pu] < rank[pv])
        {
            par[pu] = pv;
        }
        else if(rank[pv] < rank[pu])
        {
            par[pv] = pu;
        }
        else
        {
            par[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        
        vector<vector<string>> ans;
        map<string,int> email_map;
        int n =accounts.size();
        DisjointSet ds(accounts.size());
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail = accounts[i][j];
                if(email_map.find(mail) == email_map.end())
                {
                    email_map[mail] = i;
                }
                else
                {
                    // if already availabe 
                    // union of already existed usrname = val , currnode which is i
                    int val = email_map[mail];
                    ds.unionbyrank(val,i);
                }
                
            }
        }
        vector<vector<string>>emails(n);
        
        for(auto it : email_map)
        {
            int node = it.second;
            string email = it.first;
            int ult_par = ds.findUPar(node);
            emails[ult_par].push_back(email);
        }
        
        for(auto it :emails)
        {
            if(it.size() > 0)
            {
                int node = email_map[it[0]];
                node = ds.findUPar(node);
                string acname = accounts[node][0];
                vector<string>temp;
                //push account name
                temp.push_back(acname);
                
                //push all emails in temp now
                for(auto em : it)
                {
                    temp.push_back(em);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
