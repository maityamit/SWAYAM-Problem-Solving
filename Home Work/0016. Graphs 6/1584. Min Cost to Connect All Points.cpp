class DisjointSet{
	vector<int> rank,parent,size;
	public:
		DisjointSet(int n){
			rank.resize(n+1,0);
			size.resize(n+1,1);
			parent.resize(n+1);
			for(int i=0;i<=n;i++) parent[i]=i;
		}
		
		int findUltimateParent(int node){
			if(node==parent[node]){
				return node;
			}
			return parent[node] = findUltimateParent(parent[node]);
		}
		
		void unionByRank(int u,int v){
			
			int ulp_u = findUltimateParent(u);
			int ulp_v = findUltimateParent(v);
			
			if(ulp_u==ulp_v) return;
			
			if(rank[ulp_u] < rank[ulp_v]){
				parent[ulp_u] = ulp_v;
			}else if(rank[ulp_v] < rank[ulp_u]){
				parent[ulp_v] = ulp_u;
			}else{
				parent[ulp_v]=ulp_u;
				rank[ulp_u]++;
			}
		}
		
		void unionBySize(int u,int v){
			
			int ulp_u = findUltimateParent(u);
			int ulp_v = findUltimateParent(v);
			
			if(ulp_u==ulp_v) return;
			
			if(size[ulp_u] < size[ulp_v]){
				parent[ulp_u] = ulp_v;
				size[ulp_v] += size[ulp_u];
			}else{
				parent[ulp_v] = ulp_u;
				size[ulp_u] += size[ulp_v];
			}
			
		}
		
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,{i,j}});
            }
        }
        sort(edges.begin(),edges.end());
        int sum = 0;
        DisjointSet ds(points.size()+1);
        for(auto it:edges){
            if(ds.findUltimateParent(it.second.first)!=ds.findUltimateParent(it.second.second)){
                sum+=it.first;
                ds.unionByRank(it.second.first,it.second.second);
            }
        }
        return sum;
    }
};