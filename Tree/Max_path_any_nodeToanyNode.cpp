 int findMax(Node*root ,int &maxi)
    {
        if(root== NULL) return 0;
        
        int lsum = max(0,findMax(root->left,maxi));
        int rsum = max(0,findMax(root->right,maxi));
        // actual ans
        maxi = max(maxi,root->data+lsum+rsum);
        
        return root->data + max(lsum,rsum);
    }
    int findMaxSum(Node* root)
    {
      /// important assigenment to INT_MIN, as ans can be -ve
        int maxi = INT_MIN;
        findMax(root,maxi);
        return maxi;
    }
