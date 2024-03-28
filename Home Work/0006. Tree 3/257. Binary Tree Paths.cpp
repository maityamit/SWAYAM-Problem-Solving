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
    void helper(TreeNode* root,vector<int> &temp,vector<vector<int>> &ans){
        
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        if(root->left==NULL){
            helper(root->right,temp,ans);
        }else if(root->right==NULL){
            helper(root->left,temp,ans);
        }else{
            helper(root->left,temp,ans);
            helper(root->right,temp,ans);
        }
        
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(root,temp,ans);
        vector<string> amit;
        
        for(auto it:ans){
            string temp;
            for(int i=0;i<it.size();i++){
                if(i==it.size()-1) temp+=to_string(it[i]);
                else{
                    temp+=to_string(it[i]);
                    temp+="->";
                }
            }
            amit.push_back(temp);
        }
        
        return amit;
    }
};