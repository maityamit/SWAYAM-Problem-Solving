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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vt;
        if(root==NULL){
            return vt;
        }
        queue<TreeNode*> pending;
        pending.push(NULL);
        pending.push(root);
        vector<int> amm;
        while(pending.size()!=0){
            if(pending.front()==NULL){
                if(amm.size()!=0){
                    vt.push_back(amm);
                    amm.clear();
                }
                pending.pop();
                if(pending.size()==0){
                    return vt;
                }
                pending.push(NULL);
                // if(pending.front()==NULL){
                //     return vt;
                // }
            }
            TreeNode* temp = pending.front();
            pending.pop();
            amm.push_back(temp->val);
            if(temp->left!=NULL){
                pending.push(temp->left);
            }
            if(temp->right!=NULL){
                pending.push(temp->right);
            }
        }
        return vt;
    }
};