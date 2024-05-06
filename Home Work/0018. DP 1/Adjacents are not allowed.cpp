class Solution{
public:
    // int dp[10001];
    // int helper(int idx,int n,vector<vector<int>> mat){
        
    //     if(idx>=n) return 0;
        
    //     if(dp[idx]!=-1) return dp[idx];
        
    //     int a = max(mat[1][idx],mat[0][idx])+helper(idx+2,n,mat);
    //     int c = helper(idx+1,n,mat);
        
    //     return dp[idx]=max({a,c});
        
        
        
    // }
    int maxSum(int N, vector<vector<int>> mat)
    {
        // code here
        //memset(dp,-1,sizeof(dp));
        vector<int> dp(N+1,0);
        dp[0]=0;
        dp[1]=max(mat[1][0],mat[0][0]);
        for(int i=2;i<=n;i++){
            int a = max(mat[0][i-1],mat[1][i-1])+dp[i-2];
            int b = dp[i-1];
            dp[i]=max(a,b);
        }
        return dp[N];
        
    }
};