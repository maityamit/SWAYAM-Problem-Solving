class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	stack<int> st;
	void dfs2(int node,vector<bool> &vis,vector<int> adj[]){
	    vis[node]=true;
	    for(auto it:adj[node]) if(!vis[it]) dfs2(it,vis,adj);
	}
	void dfs(int node,vector<bool> &vis,vector<int> adj[]){
	    vis[node]=true;
	    for(auto it:adj[node]) if(!vis[it]) dfs(it,vis,adj);
	    st.push(node);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> trans[V+1];
        vector<int> mai[V+1];
        int mx = 0;
        for(auto it:adj){
            for(auto ele:it){
                // i->ele
                mai[mx].push_back(ele);
                trans[ele].push_back(mx);
            }
            mx++;
        }
        vector<bool> vis(V+1,false);
        for(int i=0;i<=V;i++){
            if(!vis[i]) dfs(i,vis,mai);
        }
        int ans = 0;
        for(int i=0;i<=V;i++) vis[i]=false;
        while(st.size()!=0){
            int node = st.top(); st.pop();
            if(!vis[node]){
                ans++;
                dfs2(node,vis,trans);
            }
        }
        return ans-1;
    }
};