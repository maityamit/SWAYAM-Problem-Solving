int const N = 100;
class Solution {
public:
    int dp[N+1];
    int helper(int idx,vector<int>& nums){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = nums[idx]+helper(idx+2,nums);
        int ntak = helper(idx+1,nums);
        return dp[idx]=max(take,ntak);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(0,nums);
    }
};