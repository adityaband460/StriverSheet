// Function to return a list containing the inorder traversal of the tree.
    //Morris inorder 
    // tc : O(N) amortized
    // sc : O(1)
    vector<int> inOrder(Node* root) {
       vector<int>ans;
       
       Node* curr = root;
       while(curr != NULL)
       {
           if(curr->left == NULL)
           {
               ans.push_back(curr->data);
               curr = curr->right;
           }
           else
           {
               //find out rightmost node on left subtree
               // thread inorder predecesor to curr node
               // if it is already threaded then remove thread and move right
               Node* temp = curr->left;
               while(temp->right && temp->right != curr)
               {
                   temp = temp->right;
               }
               
               if(temp->right == NULL)// this node was not threaded time to move left
               {
                   temp->right = curr;// create link to go back
                   curr= curr->left;
               }
               else // this node was threded time to move to right
               {
                   curr = temp->right;
                   temp->right = NULL; //break the link
                   ans.push_back(curr->data);// visited root
                   curr = curr->right;// now move left
               }
           }
       }
       
        return ans;
    }
