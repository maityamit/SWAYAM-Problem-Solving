class Solution {
public:
    bool ans=false;
    void dfs(int start,int end,vector<int> adj[],vector<bool> &vis){
        if(start==end){
            ans=true;
            return;
        }
        vis[start]=true;
        for(auto it:adj[start]){
            if(!vis[it]) dfs(it,end,adj,vis);
        }
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n,false);
        dfs(source,destination,adj,vis);
        return ans;
    }
};