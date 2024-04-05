class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void inorder(Node* root,vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> a,b; 
       inorder(root1,a);
       inorder(root2,b);
       
       vector<int> ans(a.size()+b.size());
       int i = 0;
       int j = 0;
       int k = 0;
       while(i<a.size() && j<b.size()){
           if(a[i]<b[j]) ans[k++]=a[i++];
           else ans[k++]=b[j++];
       }
       while(i<a.size()) ans[k++]=a[i++];
       while(j<b.size()) ans[k++]=b[j++];
       return ans;
       
    }
};