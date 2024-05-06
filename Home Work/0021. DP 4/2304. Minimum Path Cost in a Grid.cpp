class Solution {
public:
    int dp[51][2501];
    int helper(int idx,int prev,vector<vector<int>>& grid, vector<vector<int>>& moveCost){
        
        if(idx==grid.size()) return 0;
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        int mini = 1e9;
        for(int i=0;i<grid[0].size();i++){
            int temp = (grid[idx][i]+moveCost[prev][i])+
                helper(idx+1,grid[idx][i],grid,moveCost);
            mini = min(mini,temp);
        }
        return dp[idx][prev]=mini;
        
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int mini = 1e9;
        for(int i=0;i<grid[0].size();i++){
            memset(dp,-1,sizeof(dp));
            int temp = grid[0][i]+helper(1,grid[0][i],grid,moveCost);
            mini = min(mini,temp);
        }
        return mini;
    }
};