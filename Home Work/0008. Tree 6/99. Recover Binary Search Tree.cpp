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
    TreeNode* maxi(TreeNode* root){
        if(root==NULL) return root;
        TreeNode* l = maxi(root->left);
        TreeNode* r = maxi(root->right);
        TreeNode* temp = root;
        if(l!=NULL && l->val > temp->val) temp = l;
        if(r!=NULL && r->val > temp->val) temp = r;
        return temp;
    }
    TreeNode* mini(TreeNode* root){
        if(root==NULL) return root;
        TreeNode* l = mini(root->left);
        TreeNode* r = mini(root->right);
        TreeNode* temp = root;
        if(l!=NULL && l->val < temp->val) temp = l;
        if(r!=NULL && r->val < temp->val) temp = r;
        return temp;
    }
    
    void recoverTree(TreeNode* root) {
        if(root==NULL) return;
        
        TreeNode* l = maxi(root->left);
        TreeNode* r = mini(root->right);
        
        if(l!=NULL && r!=NULL && root->val>r->val && root->val<l->val){
            int temp = l->val;
            l->val = r->val;
            r->val = temp;
        }else if(l!=NULL && l->val > root->val){
            int temp = root->val;
            root->val = l->val;
            l->val = temp;
            return;
        }else if(r!=NULL && r->val < root->val){
            int temp = root->val;
            root->val = r->val;
            r->val = temp;
            return;
        }
        
        recoverTree(root->left);
        recoverTree(root->right);
    }
};