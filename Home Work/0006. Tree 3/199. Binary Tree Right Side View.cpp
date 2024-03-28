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
    vector<int> rightSideView(TreeNode* root) {
         if(root==NULL) return {};
   // Your code here
   vector<int> ans;
   queue<TreeNode*> q;
   q.push(root);
   while(q.size()!=0){
       int sz = q.size();
       for(int i=0;i<sz;i++){
           TreeNode* temp = q.front(); q.pop();
           if(i==sz-1) ans.push_back(temp->val);
           if(temp->left!=NULL) q.push(temp->left);
           if(temp->right!=NULL) q.push(temp->right);
       }
   }
   return ans;
    }
};