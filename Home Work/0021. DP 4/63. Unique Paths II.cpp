int const N = 100;
class Solution {
public:
    int dp[N+1][N+1];
    int helper(int i,int j,int m,int n,vector<vector<int>>& ob){
        if(i>m||j>n) return 0;
        if(ob[i-1][j-1]==1) return 0;
        if(i==m && j==n) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=helper(i+1,j,m,n,ob)+helper(i,j+1,m,n,ob);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        memset(dp,-1,sizeof(dp));
        return helper(1,1,ob.size(),ob[0].size(),ob);
    }
};