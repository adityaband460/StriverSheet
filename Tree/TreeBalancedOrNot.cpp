// O(N) solution
    int height(Node *root)
    {
        if(root == NULL) return 0;
        
        int leftH = height(root->left);
        // not balanced so return -1
        if(leftH== -1) return leftH;
        
        int rightH = height(root->right);
        // not balanced so return -1
        if(rightH== -1) return rightH;
        
        // not balanced so return -1
        if(abs(rightH-leftH) > 1) return -1;
        return max(leftH,rightH)+1;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return height(root) != -1;
    }
