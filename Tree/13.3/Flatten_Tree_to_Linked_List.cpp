void flatten(Node *root)
    {
        if(root==NULL) return;
        
        Node *curr = root;
        
        while(curr != NULL)
        {
            if(curr->left == NULL)
            {
                curr = curr->right;
            }
            else  //real game
            {
                Node* cl = curr->left;
                // find rightmost node in left subtree
                while(cl->right)
                {
                    cl = cl->right;
                }
                //set cl->right to curr->right
                cl->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                
                curr = curr->right;
            }
            
        }
        
    }
