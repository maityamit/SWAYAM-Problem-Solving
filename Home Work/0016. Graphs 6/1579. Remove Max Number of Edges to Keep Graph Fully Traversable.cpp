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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.rbegin(),edges.rend());
        DisjointSet bus(n);
        DisjointSet train(n);
        int cnt = 0;
        for(auto it:edges){
            if(it[0]==3){
                if((bus.findUltimateParent(it[1])!=bus.findUltimateParent(it[2]))
                  ||(train.findUltimateParent(it[1])!=train.findUltimateParent(it[2]))){
                      bus.unionByRank(it[1],it[2]);
                      train.unionByRank(it[1],it[2]);
                  }else{
                      cnt++;
                  }
            }else if(it[0]==1){
                if((bus.findUltimateParent(it[1])!=bus.findUltimateParent(it[2]))){
                    bus.unionByRank(it[1],it[2]);
                }else{
                    cnt++;
                }
            }else{
                if((train.findUltimateParent(it[1])!=train.findUltimateParent(it[2]))){
                    train.unionByRank(it[1],it[2]);
                }else{
                    cnt++;
                }
            }
        }
        int par = 0;
        for(int i=1;i<=n;i++){
            if(i==bus.findUltimateParent(i)) par++;
            if(par>1) return -1;
        }
        par=0;
        for(int i=1;i<=n;i++){
            if(i==train.findUltimateParent(i)) par++;
            if(par>1) return -1;
        }
        return cnt;
    }
};