//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> pending;
        pending.push({root,0});
        while(pending.size()!=0){
            Node* temp = pending.front().first;
            int key = pending.front().second;
            pending.pop();
            mp[key].push_back(temp->data);
            if(temp->left) pending.push({temp->left,key-1});
            if(temp->right) pending.push({temp->right,key+1});
        }
        
        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.second[it.second.size()-1]);
        }
        return ans;
    }
};