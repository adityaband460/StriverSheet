
class NodeValue{
    public:
        int maxSize;
        int minNode;
        int maxNode;
    NodeValue(int maxSize,int minNode,int maxNode)
    {
        this->maxSize = maxSize;
        this->minNode = minNode;
        this->maxNode = maxNode;
        
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    NodeValue largestBST(Node* root)
    {
        if(root == NULL)
    	{
    	    return NodeValue(0,INT_MAX,INT_MIN);
    	}
    	NodeValue left = largestBST(root->left);
    	NodeValue right = largestBST(root->right);
    	// if root is valid
    	if(root->data < right.minNode && root->data > left.maxNode )
    	{
    	    int mins = min(root->data,left.minNode);
    	    int maxs = max(root->data,right.maxNode);
    	    return NodeValue(left.maxSize+right.maxSize+1,
    	    mins,maxs);
    	}
    	else// root in not valid so all above will be invalid
    	{
    	    int size = max(left.maxSize,right.maxSize);
    	    return NodeValue(size,INT_MIN,INT_MAX);
    	}
    }
    int largestBst(Node *root)
    {
        return largestBST(root).maxSize;
    }
