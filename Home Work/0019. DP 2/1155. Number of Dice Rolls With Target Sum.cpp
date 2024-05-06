class Solution {
public:
    int mod = 1e9+7;
    int dp[1001][31];
    long long helper(int target,int n,int k){
        if(n==0 && target==0) return 1;
        if(dp[target][n]!=-1) return dp[target][n];
        long long ans = 0;
        for(int i=1;i<=k;i++){
            if(n-1>=0 && target-i>=0) ans+=helper(target-i,n-1,k);
        }
        return dp[target][n]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return helper(target,n,k);
    }
};