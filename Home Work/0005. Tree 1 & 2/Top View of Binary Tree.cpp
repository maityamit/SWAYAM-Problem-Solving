/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(q.size()!=0){
            auto it = q.front(); q.pop();
            if(!mp.count(it.second)) mp[it.second]=it.first->data;
            if(it.first->left!=NULL) q.push({it.first->left,it.second-1});
            if(it.first->right!=NULL) q.push({it.first->right,it.second+1});
        }
        vector<int> ans;
        for(auto it:mp) ans.push_back(it.second);
        return ans;
    }

};
