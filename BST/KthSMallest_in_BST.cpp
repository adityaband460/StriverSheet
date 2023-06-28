// Return the Kth smallest element in the given BST
    
    // do morris inorder traversal and find kth node
    int KthSmallestElement(Node *root, int K) {
        // morris inorder so it will take O(1) space
        
        Node* curr = root;
        while(curr != NULL)
        {
           
            if(curr->left == NULL)
            {// this means left is covered
                //print
                K--;
                if(K==0)
                break;
                curr = curr->right;
            }
            else
            {
                Node* temp = curr->left;
                while(temp->right && temp->right != curr)
                {
                    temp = temp->right;
                }
                if(temp->right == NULL)
                {
                    temp->right = curr;
                    curr = curr->left;
                }
                else//we already visited left subtree
                {
                    //print
                    K--;
                    if(K==0)
                    break;
                    temp->right = NULL;
                    curr = curr->right;
                }
            }
        }
        if(curr)
            return curr->data;
        else
            return -1;
    }
