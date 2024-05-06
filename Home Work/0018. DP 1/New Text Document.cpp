int const N = 100;
class Solution {
public:
    int dp[N+1];
    int helper(int idx,bool state,vector<int>& nums){
        if(state==true && idx>=nums.size()-1) return 0;
        if(state==false && idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = nums[idx]+helper(idx+2,state,nums);
        int ntak = helper(idx+1,state,nums);
        return dp[idx]=max(take,ntak);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        int a = helper(0,true,nums);
        memset(dp,-1,sizeof(dp));
        int b = helper(1,false,nums);
        return max(a,b);
    }
};