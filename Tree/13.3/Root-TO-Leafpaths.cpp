bool isLeaf(Node* root)
{
    return root->left==NULL && root->right == NULL;
}
void preOrder(Node* root,vector<int>&curr,vector<vector<int>>&ans)
{
    //base case
    if(root== NULL)
    {
        return;
    }
    if(isLeaf(root))
    {
        curr.push_back(root->data);
        ans.push_back(curr);
        //backtracking
        curr.pop_back();
        return;
    }
    //rec case
    curr.push_back(root->data);
    preOrder(root->left,curr,ans);
    preOrder(root->right,curr,ans);
     //backtracking
    curr.pop_back();
}
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>>ans;
    vector<int> curr;
    preOrder(root,curr,ans);
    return ans;
   
}
