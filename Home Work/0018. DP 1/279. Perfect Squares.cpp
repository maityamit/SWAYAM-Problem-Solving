int const N = 1e4;
class Solution {
public:
    int dp[N+1][101];
    int solve(int n, int val){
        if(n < 0) return 1e9;
        if(n == 0) return 0;  
        if(val > sqrt(n)) return 1e9; // no becomes more than n

        if(dp[n][val] != -1)
            return dp[n][val];

        int ans = 1e9;

        long long perfectsq = val * val;
        if(perfectsq <= n) {
            int take = 1 + solve(n - perfectsq, val);
            ans = min(ans, take);
        }

        int notTake = solve(n, val + 1); // trying with next val
        ans = min(ans, notTake);

        dp[n][val] = ans;
        return ans;
    }

    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n, 1);
    }
};
