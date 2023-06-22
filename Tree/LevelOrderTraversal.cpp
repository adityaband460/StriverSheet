vector<int> levelOrder(Node* node)
    {
        vector<int> ans;
        if(node == NULL)
            return ans;
            
        queue<Node*>q;
        q.push(node);
       
        while(!q.empty())
        {
            // number of nodes in that level
            int n = q.size(); 
            
            for(int i=0;i<n;i++)
            {
                Node* a = q.front();
                q.pop();
                ans.push_back(a->data);
                if(a->left != NULL)
                    q.push(a->left);
                if(a->right != NULL)
                    q.push(a->right);
            }
           
        }
        return ans;
    }
