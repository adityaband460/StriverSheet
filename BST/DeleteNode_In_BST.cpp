
// f() : delete node with val x and return root
Node *deleteNode(Node *root, int x) {
    
    //base case
    //NULL means x was never present in the tree
    if(root == NULL) 
        return root;
    
    //rec case
    if(root->data == x)
    {
        //0 child
         if(root->left == NULL && root->right == NULL)
         {
            delete root;
            return NULL;
         }
        //1 child
        //left
        if(root->left != NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
            
        }
        //right
        if(root ->right != NULL && root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        //2 child
        if(root->right != NULL && root->left != NULL)
        {
            //find inorder succesor
            Node* curr = root->right;
            while(curr->left)
            {
                curr = curr->left;
            }
            
            // replace root by curr and delete curr
            root->data = curr->data;
            root->right = deleteNode(root->right,curr->data);
        }
    }
    else if(x < root->data)
    {
        root->left = deleteNode(root->left,x);
    }
    else // x > root->data
    {
        root->right = deleteNode(root->right,x);
    }
    
}
