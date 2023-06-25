 Node* markParent(Node* root,unordered_map<Node*,Node*> &par)
    {
        //level order
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            if(curr->left)
            {
                par[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                par[curr->right] = curr;
                q.push(curr->right); 
            }
            
        }
    }
    Node* findNode(Node* root,int target)
    {
        if(root==NULL)
            return NULL;
        if(root->data == target)
            return root;
        
        Node* rl = findNode(root->left,target);
        if(rl !=NULL) return rl;
        Node* rr = findNode(root->right,target);
        if(rr != NULL) return rr;
        
        return NULL;
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        unordered_map<Node*,Node*> par_track;
        par_track[root] = NULL;
        markParent(root,par_track);
        Node* targetNode = findNode(root,target);
        
        // bfs like graph
        int currLvl = 0;
        unordered_map<Node*,bool>visited;
        queue<Node*>q;
        q.push(targetNode);
        visited[targetNode] = true;
        while(!q.empty())
        {
            // if k==0 then queue will contain target node
            if(currLvl == k)
                break;
            currLvl++; 
            // as this level nodes 
           // is popped by below for loop
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                Node* temp = q.front();
                q.pop();
                //par
                
                if(par_track[temp] && !visited[par_track[temp]])
                {
                    q.push(par_track[temp]);
                    visited[par_track[temp]] = true;
                }
                //left
                if(temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                //right
                if(temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                
            }
           
            
            
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
