
// Approach 2 : O(N) : while calculating height calculate diameter and pass by parameter
 // Function to return the diameter of a Binary Tree.
    int heightModified(Node* root,int &maxi)
    {
        if(root == NULL)return 0;
        
        int lh = heightModified(root->left,maxi);
        int rh = heightModified(root->right,maxi);
        
        maxi = max(maxi, lh+rh+1); // this is real game
     // return height only while returning 
        return max(lh,rh)+1;
    }
    int diameter(Node* root) {
        int ans = 0;
        heightModified(root,ans);
        return ans;
    }


------------------------------------------------------------------------------------------------------------------------------
int height(Node* root)
    {
        if(root == NULL)return 0;
        
        return max(height(root->left),height(root->right))+1;
    }
///   Approach 1; O(N^2) time complexity  : for each node height calculated
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
