/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include <map>

void bottomView(TreeNode<int>* root,vector<TreeNode<int>*> &ans) {
        // Your Code Here
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root);
            return;
        }
        if(root->left) bottomView(root->left,ans);
        if(root->right) bottomView(root->right,ans);
        
    }

vector<TreeNode<int>*> rightSideView(TreeNode<int>* root) {
   // Your code here
   vector<TreeNode<int>*> ans;
   root = root->right;
   while(root!=NULL){
       if(root->left!=NULL || root->right!=NULL) ans.push_back(root);
       if(root->right) root=root->right;
       else root=root->left;
   }
   return ans;
}

vector<TreeNode<int>*> leftView(TreeNode<int> *root)
{
   // Your code here
   vector<TreeNode<int>*> ans;
   root = root->left;
   while(root!=NULL){
       if(root->left!=NULL || root->right!=NULL) ans.push_back(root);
       if(root->left) root=root->left;
       else root=root->right;
   }
   return ans;
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    if(root==NULL) return {};
    vector<int> ans;
    if(root->left!=NULL || root->right!=NULL) ans.push_back(root->data);

    vector<TreeNode<int>*> l = leftView(root);
    vector<TreeNode<int>*> r = rightSideView(root);
    vector<TreeNode<int>*> b;
    bottomView(root,b);
    
    for(auto it:l) ans.push_back(it->data);
    for(auto it:b) ans.push_back(it->data);
    reverse(r.begin(),r.end());
    for(auto it:r) ans.push_back(it->data);
    return ans;
}
