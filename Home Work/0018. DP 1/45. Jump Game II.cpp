class Solution {
public:
    int helper(int idx,vector<int>& nums,vector<int> &dp){
        if(idx>=nums.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int mini = 1e9;
        for(int j=1;(j<=nums[idx])&&(idx+j<nums.size());j++){
            mini=min(mini,1+helper(idx+j,nums,dp));
        }
        return dp[idx]=mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};