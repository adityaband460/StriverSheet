void inOrder(Node* root,vector<int> &ans)
    {
        if(root == NULL) return ;
        inOrder(root->left,ans);
        ans.push_back(root->data);
        inOrder(root->right,ans);
    }
    vector<int> merge(vector<int>a,vector<int>b)
    {
        vector<int>ans;
        int i= 0,j=0;
        int n1 = a.size();
        int n2 = b.size();
        while(i<n1 && j<n2)
        {
            if(a[i]<b[j])
            {
                ans.push_back(a[i]);
                i++;
            }
            else
            {
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i<n1)
        {
            ans.push_back(a[i]);
            i++;
        }
        while(j < n2)
        {
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> r1,r2,ans;
       inOrder(root1,r1); //n1
       inOrder(root2,r2); //n2
       //merge 2 sorted arrays
       ans = merge(r1,r2);// n1+n2
       return ans;  // ans is simply returning inorder of 2 merged bst
    }
//  Build a Balanced BST
    Node* build(int start,int end,vector<int>in)
    {
        if(start > end) return NULL;

        int mid = (start+end)/2;
        Node* root = new Node(in[mid]);
        root->left = build(start,mid-1,in);
        root->right = build(mid+1,end,in);
        return root;
    }

