void markParent(Node* root,unordered_map<Node*,Node*> &pmap)
    {
        //level order traversal
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            
            if(temp->left)
            {
                pmap[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                pmap[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    Node* findNode(Node* root,int target)
    {
        if(root== NULL) return NULL;
        
        if(root->data == target) return root;
        
        Node* rl = findNode(root->left,target);
        Node* rr = findNode(root->right,target);
        if(rl)
        {
            return rl;
        }
        if(rr)
        {
            return rr;
        }
        return NULL;
    }
    int minTime(Node* root, int target) 
    {
        Node* targetNode = findNode(root,target);
        unordered_map<Node*,Node*>par_mark;
        markParent(root,par_mark);
        
        // bfs
        queue<Node*>q;
        unordered_map<Node*,bool>visited;
        q.push(targetNode);
        visited[targetNode] = true;
        int currLvl = 0;
        int maxd = 0;
        while(!q.empty())
        {
            maxd++;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                Node* temp = q.front();
                q.pop();
                
                if(temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(par_mark[temp] && !visited[par_mark[temp]])
                {
                    q.push(par_mark[temp]);
                    visited[par_mark[temp]] = true;
                }
            }
        }
        return maxd-1;
    }
