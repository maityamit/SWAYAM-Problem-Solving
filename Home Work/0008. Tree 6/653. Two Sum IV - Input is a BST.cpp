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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> map;
        queue<TreeNode*> pending;
        pending.push(root);
        while(pending.size()!=0){
            TreeNode* temp = pending.front();
            pending.pop();
            if(map.count(k-temp->val)>=1) return true;
            map[temp->val]++;
            if(temp->left) pending.push(temp->left);
            if(temp->right) pending.push(temp->right);
        }
        return false;
    }
};