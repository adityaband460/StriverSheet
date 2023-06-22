 vector<int> inOrder(Node* root) {
        vector<int>ans;
        stack<Node*>st;
        Node* curr = root;
        while(true)
        {
            //go to left as much as possible
            if(curr != NULL)
            {
                // push curr inside not curr->left
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                //stack can be empty here
                if(st.empty())
                    return ans;
                    
                curr = st.top();
                st.pop();
                //print
                ans.push_back(curr->data);
                //move to right
                curr = curr->right;
            }
        }
        return ans;
    }
