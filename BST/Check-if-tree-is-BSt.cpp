bool bst(Node* root,int lval,int rval)
    {
        if(root == NULL )
            return true;
        
        if(root->data >= rval || root->data <= lval)
        {
            return false;
        }
        return bst(root->left,lval,root->data)&&bst(root->right,root->data,rval);
    }
    bool isBST(Node* root) 
    {
        return bst(root,INT_MIN,INT_MAX);     
    }
