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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp;
        int maxi = -1e9;
        int mini = 1e9;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        while(q.size()!=0){
            int sz = q.size();
            map<int,vector<int>> am;
            for(int i=0;i<sz;i++){
                auto temp = q.front(); q.pop();
                maxi=max(maxi,temp.first);
                mini=min(mini,temp.first);
                am[temp.first].push_back(temp.second->val);
                if(temp.second->left!=NULL) q.push({temp.first-1,temp.second->left});
                if(temp.second->right!=NULL) q.push({temp.first+1,temp.second->right});
            }
            for(auto &it:am) sort(it.second.begin(),it.second.end());
            for(auto it:am) mp[it.first].insert(mp[it.first].end(),it.second.begin(),it.second.end());
        }
        for(int i=mini;i<=maxi;i++) ans.push_back(mp[i]);
        return ans;
    }
};