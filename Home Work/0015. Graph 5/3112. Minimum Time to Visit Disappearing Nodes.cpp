int const N = 5*1e4;
class Solution {
public:
    vector<pair<int,int>> g[N+1];
    vector<int> dijkstraAlgo(int source,int N,vector<int>& disappear){

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
	vector<int> distTo(N+1,INT_MAX);
	distTo[source] = 0;
	pq.push(make_pair(0,source));	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
        
        if(dist>distTo[prev]) continue;
        
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
            
            
            int nowLen = distTo[prev] + nextDist;
			if(distTo[next]>nowLen && nowLen<disappear[next]){
			   distTo[next] = nowLen;
			   pq.push(make_pair(distTo[next], next));
			}
		}
	}
	return distTo;
}
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        for(auto it:edges){
            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});
        }
        vector<int> dist = dijkstraAlgo(0,n,disappear);
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(dist[i]!=INT_MAX) ans[i]=dist[i];
        }
        return ans;
    }
};