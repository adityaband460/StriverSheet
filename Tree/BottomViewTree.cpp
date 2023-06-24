// ans of : 20 8 22 5 3 4 25
//   is     : 5 8 4 22 25
    vector <int> bottomView(Node *root) {
        
        vector<int> ans ;
        if(root == NULL) return ans;
        // vertical ,value (nodes having same level,vertical choose rightmost one)
        map<int,int> nodes;
        // node , vertical ,level
       queue<pair<Node*,int>> q;
       
       q.push({root,0});
       
       while(!q.empty())
       {
           pair<Node*,int> p = q.front();
           q.pop();
           int ver = p.second;
           
           // even if node is present in map
           // we we will replace it as we want
           // latest levels for that vertical
           
           nodes[ver] = p.first->data;
           
           if(p.first->left != NULL)
            {
                q.push({p.first->left,ver-1});
            }
           if(p.first->right != NULL)
           {
               q.push({p.first->right,ver+1});
           }
       }
       // map<int,int> nodes;
       for( auto it= nodes.begin();it != nodes.end();it++)
       {
           ans.push_back(it->second);
       }
       return ans;
       
    }
