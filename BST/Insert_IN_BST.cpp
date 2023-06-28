// Recursive
Node* insert(Node* root, int key) {
    
    if(root==NULL) return new Node(key);
    
    if(root->data == key)
        return root;
    
    else if(key < root->data)
    {
        root->left = insert(root->left,key);
    }
    else
    {
        root->right = insert(root->right,key);   
    }
    return root;
}
// Non Recursive
Node* insert(Node* root, int key) {
    Node* curr =root;
    Node* par = NULL;
    while( curr != NULL)
    {
        if(curr->data == key)
        {
            break;
        }
        else if(curr->data > key)
        {
            par = curr;
            curr = curr->left;
        }
        else
        {
            par = curr;
            curr = curr->right;
        }
    }
    if(curr != NULL) // root already exists
    {
        return root;
    }
    else
    {
        if(key < par->data)
        {
            par->left = new Node(key);
        }
        else
        {
            par->right = new Node(key);
        }
    }
    return root;
}
