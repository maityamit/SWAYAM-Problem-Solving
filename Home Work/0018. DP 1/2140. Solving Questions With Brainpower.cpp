class Solution {
public:
    long long helper(int idx,vector<vector<int>>& questions,vector<long long> &dp){
        
        if(idx>=questions.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        long long pick = questions[idx][0]+helper(idx+questions[idx][1]+1,questions,dp);
        long long nPick = helper(idx+1,questions,dp);
        
        return dp[idx]=max(pick,nPick);
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return helper(0,questions,dp);
    }
};