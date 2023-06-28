Node* LCA(Node *root, int n1, int n2)
        {
            if(root == NULL) return NULL;
            
            if(root->data < n1 && root->data < n2)
            {
                //both bigger than root
                return LCA(root->right,n1,n2);
            }
            else if(root->data > n1 && root->data > n2)
            {
                //both smaller than root
                return LCA(root->left,n1,n2);
            }
            else
            {
                // either one of them is n1,n2
                // or root is  inbetween them
                // so our ans is root
                return root;
            }
        }
