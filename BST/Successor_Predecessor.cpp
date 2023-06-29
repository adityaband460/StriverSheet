void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        Node* curr = root; 
        //predecessor
        while( curr != NULL)
        {
            if(key <= curr->key)
            {
                //key is less than or equal to root
                curr = curr->left;
            }
            else
            {
                pre = curr;
                curr = curr->right;
            }
        }
        curr = root; 
        //successor
        while(curr != NULL)
        {
            // key is greater or equal to root
            //
            if(curr->key <= key)
            {
                curr = curr->right;
            }
            else
            {
                suc = curr;
                curr = curr->left;
            }
            
        }
    }
