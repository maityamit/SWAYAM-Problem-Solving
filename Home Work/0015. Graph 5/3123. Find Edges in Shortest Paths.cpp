int const N = 5*1e4;
class Solution {
public:
    vector<pair<int,int>> g[N+1];
    // map<int,vector<int>> mp;
    vector<int> dijkstraAlgo(int source,int N){
    
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
	    vector<int> distTo(N+1,1e9);
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
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<bool> ans(edges.size(),false);
        for(auto it:edges){
            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int> front = dijkstraAlgo(0,n);
        vector<int> back = dijkstraAlgo(n-1,n);
        
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
//             cout<<front[a]+back[b]+edges[i][2]<<" ";
            
            if(front[a]+back[b]+edges[i][2]==front[n-1]){
                ans[i]=true;
            }
            
            if(front[b]+back[a]+edges[i][2]==front[n-1]){
                ans[i]=true;
            }
        }
        
        // for(auto it:mp){
        //     cout<<it.first<<" : ";
        //     for(auto ele:it.second) cout<<ele<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};