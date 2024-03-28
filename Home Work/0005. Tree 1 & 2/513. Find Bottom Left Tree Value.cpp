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
    int findBottomLeftValue(TreeNode* root) {
        
        int MX=0;
        if(root==NULL) return 0;
        map<int,int> mp;
        queue<pair<TreeNode*,int>> pending;
        pending.push({root,0});
        while(pending.size()!=0){
            TreeNode* temp = pending.front().first;
            int lvl = pending.front().second;
            pending.pop();
            MX=max(MX,lvl);
            
            if(!(mp.count(lvl)>=1)){
                mp[lvl] = temp->val;
            }
            
            
            if(temp->left) pending.push({temp->left,lvl+1});
            if(temp->right) pending.push({temp->right,lvl+1});
        }
        
        return mp[MX];
    }
};