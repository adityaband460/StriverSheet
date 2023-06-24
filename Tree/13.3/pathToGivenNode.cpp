bool helper(TreeNode* root,int B,vector<int>& ans)
 {
     if(root == NULL) return false;
     if(root->val == B) {
         ans.push_back(B);
         return true;
     }
     else
     {
         ans.push_back(root->val);
         if(helper(root->left,B,ans) ||
         helper(root->right,B,ans))
         {
             return true;
         }
         
         ans.pop_back();
         return false;
     }
 }
vector<int> pathToGivenNode(TreeNode* A, int B) {
    vector<int> ans;
    helper(A,B,ans);
    return ans;
}
