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
    map<long long,int> mp;
    long long sum = 0;
    int ans = 0;
    void helper(TreeNode* root,int target){
        if(root==NULL) return;
        sum+=root->val;
        // if(root->val==3) for(auto it:mp) cout<<it.first<<" ";
        if(mp.count((sum-target))>0) ans+=mp[sum-target];
        mp[sum]++;
        helper(root->left,target);
        helper(root->right,target);
        mp[sum]--;
        if(mp[sum]==0) mp.erase(sum);
        sum-=root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]++;
        helper(root,targetSum);
        return ans;
    }
};