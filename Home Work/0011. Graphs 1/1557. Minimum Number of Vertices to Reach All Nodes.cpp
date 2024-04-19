class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> inOrder(n,0);
        for(auto it:edges) inOrder[it[1]]++;
        vector<int> ans;
        for(int i=0;i<n;i++) if(inOrder[i]==0) ans.push_back(i);
        return ans;
    }
};