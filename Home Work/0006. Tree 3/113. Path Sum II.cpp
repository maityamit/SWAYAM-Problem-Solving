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
    vector<vector<int>>ans;
    vector<int> temp;
    void helper(TreeNode* root,int targetSum){
        if(root==NULL) return;
        
        temp.push_back(root->val);
        
        if(!root->left && !root->right && targetSum-root->val==0){
            ans.push_back(temp);
        }
        helper(root->left , targetSum-root->val);
        helper(root->right , targetSum-root->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        helper(root,targetSum);
        return ans;
    }
};