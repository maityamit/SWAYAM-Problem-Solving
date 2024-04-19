class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<bool> &vis){
        vis[node]=true;
        for(auto it:adj[node]) if(!vis[it]) dfs(it,adj,vis);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        vector<bool> vis(n+1,false);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(isConnected[i-1][j-1]==1) adj[i].push_back(j);
            }
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};