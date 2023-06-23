


bool isLeaf(Node *curr)
    {
        return !curr->left && !curr->right;
    }
    void leftBoundary(Node* curr,vector<int> & ans)
    {
        while(curr != NULL)
        {
            // if it is not a leaf node
            if(!isLeaf(curr))
                ans.push_back(curr->data);
            
            if(curr->left != NULL)
                curr = curr->left;
            else 
                curr = curr->right;
        }
    }
    void rightBoundary(Node* curr,vector<int> & ans)
    {
        vector<int>temp;
        while(curr != NULL)
        {
            if(!isLeaf(curr))
                temp.push_back(curr->data);
            
            if(curr->right != NULL)
                curr = curr->right;
            else 
                curr = curr->left;
        }
        //reverse the temp and push in ans
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back(temp[i]);
        }
    }
    void preOrder(Node* root,vector<int>&ans)
    {
        if(root == NULL)return;
        
        //if root is leaf node push in ans
        if(root->left == NULL && root->right == NULL)
            ans.push_back(root->data);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        //left boundary
        Node* curr = root;
        if(curr == NULL) return ans;
        
        ans.push_back(root->data);
        if(isLeaf(curr))
            return ans;
            
        //////////////////
        curr = curr->left;
        leftBoundary(curr,ans);
        
        //leaves
        preOrder(root,ans);
        
        // right boundary in reverse
        curr = root->right;
         rightBoundary(curr,ans);
        
        
        return ans;
    }
