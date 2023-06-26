 // works only for complete Binary Tree
int leftHeight(Node* root)// works in log n time
    {
        int lh = 1;
        while(root->left)
        {
            lh++;
            root = root->left;
        }
        return lh;
    }
    int rightHeight(Node* root)
    {
        int rh = 1;
        while(root->right)
        {
            rh++;
            root= root->right;
        }
    }
    // works only for complete Binary Tree
    int countNodes(Node* root) {
        if(root==NULL) return 0;
        int lh = leftHeight(root); // include root and longest leaf in path
        int rh = rightHeight(root);// include root and longest leaf in path
        
        if(lh == rh) // this is root with perfect tree
        {
            return 1<<lh -1; // 2^h - 1;
        }
        
        return countNodes(root->left) + countNodes(root->right) +1;
        
    }
