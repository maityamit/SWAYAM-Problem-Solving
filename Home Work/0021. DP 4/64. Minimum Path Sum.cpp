int const N = 200;
class Solution {
public:
    int dp[N+1][N+1];
    int helper(int i,int j,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i==n-1 && j==m-1) return grid[i][j];
        if(i>=n || j>=m) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(helper(i+1,j,grid),helper(i,j+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,grid);
    }
};