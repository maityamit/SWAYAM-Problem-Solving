/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = helper(arr,start,mid-1);
        root->right = helper(arr,mid+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        if(head==NULL){
            return NULL;
        }
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        temp=head;
        int i=0;
        int *arr = new int[count];
        while(temp!=NULL){
            arr[i]=temp->val;
            i++;
            temp=temp->next;
        }
        return helper(arr,0,count-1);
    }
};