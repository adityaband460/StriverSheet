// isReverse = true means iterator will move (end to start) and upon calling
// next() method will move backwords (inorder traversal);
// if(isReverse==false) means iterator will move start to end and upon calling
// next() method will move forward (inorder);
class BSTiterator
{
    private:
        stack<Node*>st;
        bool isReverse;
    public :
    BSTiterator(Node* root,bool isReverse){
        this->isReverse = isReverse;
        pushAll(root);// to push root and its left or its right depend on reverse
    }
    int next(){
        if(hasNext()){
            Node* ans = st.top();
            st.pop();
            if(!isReverse)
            {
                pushAll(ans->right);
            }
            else
            {
                pushAll(ans->left);
            }
            return ans->data;
        }
        return -1;
    }
    bool hasNext(){
       return !st.empty();
    }
    void pushAll(Node* root){
        while(root){
            st.push(root);
            if(!isReverse){
                root= root->left;
            }
            else{
                root = root->right;
            }
        }
    }
};

class Solution{
  public:

    int isPairPresent(struct Node *root, int target){
        if(root == NULL)return 0;
        BSTiterator l(root,false);
        BSTiterator r(root,true);
        
        int i = l.next();
        int j = r.next();
        while(i < j)
        {
            if(i+j == target)
            {
                return 1;
            }
            else if(i+j < target)
            {
                i =l.next();
            }
            else
            {
                j = r.next();
            }
        }
        return 0;
    }
};
