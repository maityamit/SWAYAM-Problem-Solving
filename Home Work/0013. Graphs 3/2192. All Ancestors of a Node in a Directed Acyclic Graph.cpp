int const N = 1000;
class Solution {
public:
    vector<int> adj[N+1];
    void dfs(int node,map<int,int> &mp){
        mp[node]++;
        for(auto it:adj[node]){
            if(!mp.count(it)) dfs(it,mp);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            vector<int> temp;
            map<int,int> mp;
            dfs(i,mp);
            for(auto it:mp) if(it.first!=i) temp.push_back(it.first);
            ans.push_back(temp);
        }
        return ans;
    }
};