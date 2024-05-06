class Solution {
public:
    vector<int> dijkstra(int src,int N,vector<pair<int,int>> g[]){

    vector<int> dist(N,1e9);
    vector<int> vis(N,false);

    priority_queue<pair<int,int>,vector<pair<int,int>>,
    greater<pair<int,int>>> pq;
    pq.push({0,src});
    dist[src]=0;
    dist[0]=0;
    
    while(pq.size()!=0){
        auto node = pq.top();
        pq.pop();
        int v = node.second;
        int dis = node.first;
        
        if(vis[v]) continue;
        vis[v]=true;

        for(auto child:g[v]){
            int child_v = child.first;
            int wt = child.second;
            if(dist[v]+wt < dist[child_v]){
                dist[child_v]=dist[v]+wt;
                pq.push({dist[child_v],child_v});
            }
        }
        }
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> g[n+1];
        for(auto it:times){
            g[it[0]].push_back({it[1],it[2]});
        }
        vector<int> ans = dijkstra(k,n+1,g);
        int maxi = 0;
        // for(auto it:ans) cout<<it<<" ";
        for(int i=1;i<=n;i++){
            if(ans[i]==1e9) return -1;
            maxi=max(maxi,ans[i]);
        }
        return maxi;
    }
};