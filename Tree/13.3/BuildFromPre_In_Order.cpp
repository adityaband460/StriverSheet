 Node* build(int in[],int pre[],int inStart,int inEnd,int preStart,int preEnd)
    {
        // this will return root
        //if nothing is in array
        if(inStart > inEnd || preStart > preEnd) return NULL;
        
        int rdata = pre[preStart];
        Node* root = new Node(rdata);
       
        // find root in inorder
        int rindex =0;
        // find root in inorder
        for(int i=inStart;i<=inEnd;i++)
        {
            if(rdata == in[i])
            {
                rindex = i;
                break;
            }
        }
        int lSize = rindex - inStart;
        //build root->left subtree
        root->left = build(in,pre,inStart,rindex-1,preStart+1,preStart+lSize);
        //build root->right subtree
        root->right = build(in,pre,rindex+1,inEnd,preStart+lSize+1,preEnd);
        
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        return build(in,pre,0,n-1,0,n-1);
    }
