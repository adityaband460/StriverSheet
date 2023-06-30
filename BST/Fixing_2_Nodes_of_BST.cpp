 // here prev means inorder predecessor not parent
    Node *prev=NULL ,*first = NULL,*last,*middle;
    void inorder(Node* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        
        if(prev && prev->data >= root->data )
        {
            if(first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root; //every time prev will be changing 
        inorder(root->right);
    }
    void correctBST( struct Node* root )
    {
        inorder(root);
        if(last==NULL){ last = middle;}
        
        // cout<<first->data<<" "<<last->data<<endl;
        swap(first->data,last->data);
    }
