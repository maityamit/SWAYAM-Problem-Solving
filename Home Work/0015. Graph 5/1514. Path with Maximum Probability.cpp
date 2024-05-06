class Solution {
public:
    double dijkstraAlgo(int src,int end,int n,vector<pair<int,double>> g[]){

        priority_queue<pair<double,int>,vector<pair<double,int>>,
            greater<pair<double,int>>> pq;
	    vector<double> distTo(n,1e9);
	    distTo[src] = 0;
	    pq.push(make_pair(0,src));
	    while( !pq.empty() ){
	    	double dist = pq.top().first;
	    	int prev = pq.top().second;
	    	pq.pop();
	    	vector<pair<int,double> >::iterator it;
	    	for( it = g[prev].begin() ; it != g[prev].end() ; it++){
	    		int next = it->first;
	    		double nextDist = it->second;
	    		if( distTo[next] > distTo[prev] + nextDist){
	    			distTo[next] = distTo[prev] + nextDist;
	    			pq.push(make_pair(distTo[next], next));
	    		}
	    	}
	    }
        return distTo[end];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        vector<bool> vis(n,false);
        int id = 0;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],(-1)*log2(succProb[id])});
            adj[it[1]].push_back({it[0],(-1)*log2(succProb[id])});
            id++;
        }
        double res = dijkstraAlgo(start,end,n,adj);
        return (double)1/pow(2,res);
    }
};