class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    bool bst(Node* root, int max,int min){
        if(root==NULL) return true;
        else if(root->data>=max or root->data<=min) return false;
        else return bst(root->left,root->data,min) && bst(root->right,max,root->data);
    }
    int sz(Node* root){
        if(root==NULL) return 0;
        else return 1+sz(root->left)+sz(root->right);
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	if(bst(root,1e9,-1e9)) return sz(root);
    	else return max(largestBst(root->left),largestBst(root->right));
    }
};