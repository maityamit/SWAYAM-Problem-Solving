class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
       map<int,int> mp;
       queue<pair<Node*,int>> q;
       q.push({root,0});
       while(q.size()!=0){
           auto it = q.front(); q.pop();
           mp[it.second%2]+=it.first->data;
           if(it.first->left!=NULL) q.push({it.first->left,it.second+1});
           if(it.first->right!=NULL) q.push({it.first->right,it.second+1});
       }
       return mp[0]-mp[1];
    }
};