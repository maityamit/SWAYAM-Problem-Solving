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
    TreeNode* helper(int arr[],int start,int end){
        if(start>end){
            return NULL;
        }
        int mid = (start+end)/2;
        TreeNode* temp = new TreeNode(arr[mid]);
        TreeNode* l = helper(arr,start,mid-1);
        TreeNode* r = helper(arr,mid+1,end);
        temp->left=l;
        temp->right=r;
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int *arr = new int[nums.size()];
        for(int i=0;i<nums.size();i++) arr[i]=nums[i];
        return helper(arr,0,nums.size()-1);
    }
};