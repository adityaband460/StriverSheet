int height(Node* root)
    {
        if(root == NULL)return 0;
        
        return max(height(root->left),height(root->right))+1;
    }
    int diameter(Node* root) {
        if(root== NULL) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        int d = lh + rh +1;
        
        int ld = diameter(root->left);
        int rd = diameter(root->right);
        // compare 3 things
        // path passing through left : left diameter
        // path passing through right : right diameter
        // or path passing through curr root
        return max(max(ld,rd),d);
    }
