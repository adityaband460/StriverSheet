 //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // If anyone or both are NULL
        if(r1== NULL || r2== NULL)
        {
            // if both are null
            return r1==r2;
        }
        // now both are not NULL after this
        return r1->data == r2->data && 
        isIdentical(r1->left,r2->left) && 
        isIdentical(r1->right,r2->right);
        
    }
