    vector<int> verticalOrder(Node *root)
    {
        // here no need of sorting at node 5,6 so no need of multiset
        // vertical, level,array
        map<int,map<int,vector<int>>>nodes;
        // node,vertical,horizontal
        queue<pair<Node*,pair<int,int>>>todo;
        
        todo.push({root,{0,0}});//0vertical 0level
        
        //level order traversal
        while(!todo.empty())
        {
            pair<Node*,pair<int,int>> p = todo.front();
            todo.pop();
            
            Node* temp = p.first;
            int x = p.second.first;//vertical
            int y = p.second.second;//level
            nodes[x][y].push_back(temp->data);
            
            if(temp->left != NULL)
            {
                todo.push({temp->left,{x-1,y+1}});
            }
            if(temp->right != NULL)
            {
                 todo.push({temp->right,{x+1,y+1}});
            }
        }
        // map<int,map<int,vector<int>>>nodes;
        vector<int>ans;
        for(auto p : nodes)
        {
            for(auto q : p.second )
            {
                ans.insert(ans.end(),q.second.begin(),q.second.end());
            }
        }
        return ans;
    }
