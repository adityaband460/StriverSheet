//Function to return a list containing elements of left view of the binary tree.
void preModified(Node* root,int level,vector<int>&ans)
{
    if(root == NULL) return;
    if(level == ans.size())
        ans.push_back(root->data);
    
    preModified(root->left,level+1,ans);
    preModified(root->right,level+1,ans);
}

vector<int> leftView(Node *root)
{
    // pre order
    // 1st element of each level
    // ds.size() == lvel then only add that element
    vector<int> ans;
    preModified(root,0,ans);
    return ans;
}
//Function to return list containing elements of right view of binary tree.
    void revPreOrder(Node *root,int lvl,vector<int>&ans)
    {
        if(root == NULL)return;
        if(lvl==ans.size()) ans.push_back(root->data);
        
        revPreOrder(root->right,lvl+1,ans);
        revPreOrder(root->left,lvl+1,ans);
    }
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       revPreOrder(root,0,ans);
       return ans;
    }
