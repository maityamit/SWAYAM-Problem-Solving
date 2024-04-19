const int N = 40000;
int dp[N+1];
void dfs(int node,int pV,vector<int> adj[]){
  int cnt = 0;
  for(auto it:adj[node]){
    if(it==pV) continue;
    dfs(it,node,adj);
    cnt = max(cnt,dp[it]);
  }
  dp[node]=1+cnt;
}
 
int bHelper(int node,vector<int> adj[]){
  queue<pair<int,pair<int,int>>> q;
  q.push({1,{node,-1}});
  int maxi = 0;
  int no = -1;
  while(q.size()!=0){
     auto it = q.front(); q.pop();
     if(it.first>maxi){
      maxi=it.first;
      no = it.second.first;
     }
     for(auto i:adj[it.second.first]){
      if(i==it.second.second) continue;
      q.push({it.first+1,{i,it.second.first}});
     }
  }
  return no;
}
int Solution::solve(vector<int> &A) {
    vector<int> adj[N+1];
    for(int i=0;i<A.size();i++){
        if(A[i]==-1) continue;
        adj[i].push_back(A[i]);
        adj[A[i]].push_back(i);
    }
    if(1==A.size()) return 0;
 
     int node = bHelper(1,adj);
     dfs(node,-1,adj);
     return dp[node]-1;
}
