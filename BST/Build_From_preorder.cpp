    //Function that constructs BST from its preorder traversal.
    Node* BuildBSTfromPre(int pre[],int &i,int size,int maxBoundary)
    {
        //base case
        if(i >= size) return NULL;
        
        if(pre[i] >= maxBoundary)
            return NULL;
            
        Node* root = newNode(pre[i]);
        i++;
        root->left = BuildBSTfromPre(pre,i,size,root->data);
        
        root->right = BuildBSTfromPre(pre,i,size,maxBoundary);
        
        return root;
    }
    Node* post_order(int pre[], int size)
    {
        int a= 0;
        return BuildBSTfromPre(pre,a,size,INT_MAX);
        
    }
// if this approach is hard try below approach
// https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
