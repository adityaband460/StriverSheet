bool isMirror(Node* r1 , Node* r2)
    {
        if(r1 == NULL && r2 == NULL) return true;
        else if(r1==NULL && r2 != NULL) return false;
        else if(r1!= NULL && r2 == NULL) return false;
        
        if(r1->data != r2->data) return false;
        
        return isMirror(r1->left,r2->right) && 
        isMirror(r1->right,r2->left);
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    if(root == NULL) return true;
	    
	    return isMirror(root->left,root->right);
    }
