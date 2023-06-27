//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
    //MOrris preorder
    // tc : O(N) amortized
    // sc : O(1)
    vector<int>ans;
    Node* curr = root;
    while(curr != NULL)
    {
        //case 1:
        if(curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        //case 2: 
        // find preorder predecessor of curr 
        // if that nodes right == NULL , connect it to curr
        // if it was already connected remove it , move right
        else
        {
           // here we can't visite curr as we don't know it was
           // prev visited or not
            Node* temp = curr->left;
            while(temp->right != NULL && temp->right != curr)
            {
                temp = temp->right;
            }
            if(temp->right == NULL)
            {
                // this means root and its left was not prev visited
                ans.push_back(curr->data); // 
                temp->right = curr;
                curr = curr->left;
            }
            else
            {
                // this means root and its left was previously visited
                curr = temp->right;
                temp->right = NULL;
                curr = curr->right;
            }
        }
    }
   
    return ans;
    // root left right
    
}
