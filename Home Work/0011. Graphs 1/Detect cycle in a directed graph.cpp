class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> adj[],vector<bool>& vis,vector<bool>& pathVis){
        vis[node]=true;
        pathVis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)) return true;
            }else if(pathVis[it]==true){
                return true;
            }
        }
        pathVis[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,false);
        vector<bool> pathVis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]) if(dfs(i,adj,vis,pathVis)) return true;
        }
        return false;
    }
};