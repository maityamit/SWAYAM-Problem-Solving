class Solution {
public:
    bool helper(int node,vector<bool> &vis,vector<int> &color,vector<int> adj[]){
        vis[node]=true;
        queue<pair<int,int>> q;
        q.push({node,0});
        color[node]=0;
        vis[node]=true;
        while(q.size()!=0){
            auto tn = q.front(); q.pop();
            for(auto it:adj[tn.first]){
                if(!vis[it]){
                    vis[it]=true;
                    color[it]=!tn.second;
                    q.push({it,!tn.second});
                }else if(vis[it]&&color[it]==tn.second){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for(int i=0;i<graph.size();i++) for(auto it:graph[i]) adj[i].push_back(it);
        vector<bool> vis(n,false);
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(helper(i,vis,color,adj)==false){
                    return false;
                }
            }
        }
        return true;
    }
};