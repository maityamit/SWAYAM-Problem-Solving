class Solution {
public:
    int dp[1001][1001];
    int helper(int idx,int target,vector<int>& nums){
        if(target==0) return 0;
        if(idx==nums.size()||target<0) return -1e9;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int a=1+helper(idx+1,target-nums[idx],nums);
        int b = helper(idx+1,target,nums);
        return dp[idx][target]=max(a,b);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int val = helper(0,target,nums);
        if(val<0) return -1;
        else return val;
    }
};