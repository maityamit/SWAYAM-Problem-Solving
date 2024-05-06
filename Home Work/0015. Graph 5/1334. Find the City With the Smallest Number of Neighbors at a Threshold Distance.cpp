class Solution {
public:
    vector<pair<int,int>> g[101];
    vector<int> dijkstraAlgo(int source,int N){

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
	vector<int> distTo(N+1,INT_MAX);
	distTo[source] = 0;
	pq.push(make_pair(0,source));	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}
	return distTo;
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int mini = 1e9;
        int ans = -1;
        for(auto it:edges){
            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});
        }
        for(int i=0;i<n;i++){
            vector<int> temp = dijkstraAlgo(i,n);
            int cnt = 0;
            for(auto it:temp) cnt+=(it<=distanceThreshold);
            if(mini>=cnt){
                mini=cnt;
                ans=max(ans,i);
            }
        }
        return ans;
    }
};