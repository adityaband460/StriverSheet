vector <int> preorder(Node* root)
{
    vector<int>ans;
   stack<Node*>st;
  st.push(root);
  // here we are pushing curr->right , curr->left
  while(!st.empty())
  {
      Node* curr = st.top();
      st.pop();
      ans.push_back(curr->data);
      if(curr->right != NULL)
        st.push(curr->right);
        
     if(curr->left != NULL)
        st.push(curr->left);
  }
  
   
    return ans;
    // root left right
    
}
