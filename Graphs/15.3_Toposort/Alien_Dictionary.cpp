void bfs(queue<int>&q,vector<int>adj[],vector<int>&topo,vector<int>&indegree)
    {
        while(!q.empty())
        {
            int node = q.front();q.pop();
            
            topo.push_back(node);
            
            for(int nbr : adj[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                    q.push(nbr);
            }
            
        }
    }
    
    string findOrder(string dict[], int N, int K) {
        // total K vertices will be there
        vector<int>adj[K];
        // to process N strings
        for(int i=0;i<N-1;i++)
        {
            // compare string i and i+1 th
            int s1=0,s2=0; 
            // bug fix
            int k = min(dict[i].length(),dict[i+1].length());
            while(dict[i][s1] == dict[i+1][s2])
            {
                s1++;
                s2++;
                if(s1 >= k || s2 >= k)
                    break;
            }
            if(s1 <k && s2 <k)
            adj[dict[i][s1]-'a'].push_back(dict[i+1][s2]-'a');
            
        }
        // indegree K chars so k vertices
        vector<int>indegree(K,0);
        for(int i=0;i<K;i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        //topo sort
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<K;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        bfs(q,adj,topo,indegree);
        
        string ans;
        for(int i=0;i<K;i++)
        {
            // cout<<topo[i]<<" ";
            ans.push_back(char(topo[i]+'a'));
        }
        // cout<<ans;
        
        return ans;
    }
