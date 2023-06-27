// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //level order traversal
        string ans = "";
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL)
            {
                ans.append("#,");
            }
            else
            {
                ans.append(to_string(temp->val)+',');    
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;

        stringstream ss(data);
        string str;
        getline(ss,str,',');
        int rdata = stoi(str);
        //level order traversal
       TreeNode* root = new TreeNode(rdata);
       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty())
       {
           TreeNode* curr = q.front();
           q.pop();
           //left of root
           getline(ss,str,',');
           if(str=="#")
           {
               curr->left = NULL;
           }
           else
           {
                TreeNode* left = new TreeNode(stoi(str));
                curr->left = left;
                q.push(curr->left);
           }
           
            //right of root
            getline(ss,str,',');
            if(str=="#")
            {
                curr->right = NULL;
            }
            else
            {
                TreeNode* right = new TreeNode(stoi(str));
                curr->right  = right;
                q.push(curr->right);
            }

       }
       return root;
    }
