class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int>> edges[n];
        
        for(auto it:flights){
            edges[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(q.size()!=0){
            int stop = q.front().first;
            int node  =q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if(stop>K) continue;
            
            for(auto it:edges[node]){
                if(stop<=K && (cost+it.second < dist[it.first])){
                    dist[it.first]=cost+it.second;
                    q.push({stop+1,{it.first,dist[it.first]}});
                }
            }
            
        }
        
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};