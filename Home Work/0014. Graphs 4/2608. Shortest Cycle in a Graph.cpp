class Solution {
public:
    int depth(int n,int node,vector<int> adj[]){
        int ans = 1e9;
        vector<int> dist(n,1e9);
        vector<int> parent(n,-1);
        dist[node]=0;
        queue<int> q;
        q.push(node);
        
        while(q.size()!=0){
            int temp_node = q.front();
            q.pop();
            
            for(auto it:adj[temp_node]){
                if(1e9==dist[it]){
                    dist[it]=1+dist[temp_node];
                    parent[it]=temp_node;
                    q.push(it);
                }else if(parent[temp_node]!=it && parent[it]!=temp_node){
                    ans = min(ans,dist[temp_node]+1+dist[it]);
                }
            }
        }
        return ans;
        
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<int> dfsVis(n,0);
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = 1e9;
        for(int i=0;i<n;i++){
            if(vis[i]==false) ans = min(ans,depth(n,i,adj));
        }
        if(ans==1e9) return -1;
        else return ans;
    }
};