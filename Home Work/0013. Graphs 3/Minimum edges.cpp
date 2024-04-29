class Solution{
    public:
    int const N = 1e5;
    vector<int> dijkstraAlgo(int source,int N,vector<pair<int,int>> g[]){

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
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<pair<int,int>> g[N+1];
            for(auto it:edges){
                g[it[0]].push_back({it[1],0});
                g[it[1]].push_back({it[0],1});
            }
            vector<int> arr = dijkstraAlgo(src,n,g);
            if(arr[dst]==INT_MAX) return -1;
            else return arr[dst];
        }
};