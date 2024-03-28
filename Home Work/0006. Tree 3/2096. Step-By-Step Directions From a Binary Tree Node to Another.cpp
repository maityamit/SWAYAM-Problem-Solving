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
    map<int,vector<pair<char,int>>> adj;
    void construct(TreeNode* root){
        if(root==NULL) return;
        if(root->left!=NULL){
            adj[root->val].push_back({'L',root->left->val});
            adj[root->left->val].push_back({'U',root->val});
            construct(root->left);
        }
        if(root->right!=NULL){
            adj[root->val].push_back({'R',root->right->val});
            adj[root->right->val].push_back({'U',root->val});
            construct(root->right);
        }
    }
    bool dfs(int start,int end,string &ans,int par=-1){
        if(start==end) return true;
        for(auto it:adj[start]){
            if(it.second==par) continue;
            ans+=it.first;
            if(dfs(it.second,end,ans,start)==true) return true;
            ans.pop_back();
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        construct(root);
        string ans = "";
        dfs(startValue,destValue,ans);
        return ans;
    }
};