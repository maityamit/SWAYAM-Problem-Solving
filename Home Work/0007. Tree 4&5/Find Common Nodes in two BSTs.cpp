class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    map<int,int> mp;
    void help(Node* root){
        if(root==NULL) return;
        mp[root->data]++;
        help(root->left);
        help(root->right);
    }
    vector<int> ans;
    void helper2(Node* root){
        if(root==NULL) return;
        if(mp[root->data]>0) ans.push_back(root->data);
        helper2(root->left);
        helper2(root->right);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     help(root1);
     helper2(root2);
     sort(ans.begin(),ans.end());
     return ans;
    }
};