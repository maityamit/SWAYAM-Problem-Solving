class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> inOrder(n,0);
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
            inOrder[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(inOrder[i]==0) q.push(i);
        vector<int> ans;
        while(q.size()!=0){
            int node = q.front(); q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                inOrder[it]--;
                if(inOrder[it]==0) q.push(it);
            }
        }
        if(ans.size()==n) return ans;
        else return {};
    }
};