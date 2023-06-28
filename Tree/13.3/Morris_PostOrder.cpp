// Postorder traversal
// Without recursion and without stack
vector<int> postorderTraversal(TreeNode* root)
{
	vector<int> res;
    TreeNode* curr = root;
    // root right left   //rev postorder
    while(curr != NULL)
    {
        if(curr ->right == NULL)
        {
            res.push_back(curr->key);
            curr = curr->left;
        }
        else
        {
            TreeNode* temp = curr->right;
            // find leftmost node in right subtree
            while(temp->left != NULL && temp->left != curr)
            {
                temp = temp->left;
            }
            if(temp->left == NULL) // we are visiting root 1st time
            {// no threads are connected
                temp->left = curr;//create link like rev inorder
                res.push_back(curr->key);// root right left ,
                // so print root first then move right
                curr = curr-> right;
            }
            else // this means link is present 
            {// so we already visited this root
                //no need to visit again 
                // remove the link
                temp->left = NULL;
                curr = curr->left;
            }
            
        }
    }
	return res;
}
