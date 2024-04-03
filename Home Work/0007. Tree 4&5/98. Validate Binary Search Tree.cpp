/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int MAX(TreeNode* root){
    if(root==NULL){
        return INT_MIN;
     }
     int left_ans = MAX(root->left);
     int right_ans = MAX(root->right);
     return max(root->val,max(left_ans,right_ans));
    }
    int MIN(TreeNode* root){
    if(root==NULL){
        return INT_MAX;
    }
    int left_ans = MIN(root->left);
    int right_ans = MIN(root->right);
    return min(root->val,min(left_ans,right_ans));
    }
    bool isValidBST(TreeNode* root) {
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    int left_ans = MAX(root->left);
    int right_ans = MIN(root->right);
        
    if(root->left==NULL){
         return (root->val < right_ans) && isValidBST(root->right);
    }
    if(root->right==NULL){
        return (root->val > left_ans) && isValidBST(root->left);
    }
    
     return (root->val > left_ans) && (root->val < right_ans) && isValidBST(root->left) && isValidBST(root->right);
    }
};