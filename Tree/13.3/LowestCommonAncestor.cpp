//Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        //base case
       if(root == NULL)
       {
           return NULL;
       }
       if(root->data == n1||root->data ==n2)
            return root;
       
       // rec case
       Node* left = lca(root->left,n1,n2);
       Node* right = lca(root->right,n1,n2);
       
       if(left != NULL && right != NULL)
       {
           return root;
       }
       else if(left==NULL && right != NULL)
       {
           return right;
       }
       else if(left !=NULL && right==NULL)
       {
           return left;
       }
       else
       {
           return NULL;
       }
       
    }
