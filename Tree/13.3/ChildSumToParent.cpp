 //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        //if node is null or both child nodes are null, we return true.
        if(root == NULL || (root->left==NULL && root->right ==NULL)) return 1;
        
        int rld =0 , rrd = 0;
        //if left child is not null then we store its value.
        if(root->left)
        {
            rld = root->left->data;
        }
        //if right child is not null then we store its value.
         if(root->right)
        {
            rrd = root->right->data;
        }
    //if sum of stored data of left and right child is equal to the current
    //node data and recursively for the left and right subtree, parent data 
    //is equal to sum of child data then we return true.
        if(rld + rrd == root->data && isSumProperty(root->left)&&
        isSumProperty(root->right) )
            return 1;
        else 
            return 0;
        // at each node check it is sum of its children or not
    }
