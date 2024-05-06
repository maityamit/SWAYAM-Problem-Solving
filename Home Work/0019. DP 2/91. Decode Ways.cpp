class Solution {
public:
    int ways(int idx,string &s,vector<int> &dp){
        if(idx==s.length()) return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
        int a = ways(idx+1,s,dp);
        string str;
        str+=s[idx];
        if(idx+1<s.length()){
            str+=s[idx+1];
            if(stoi(str)<=26) return dp[idx]=a+ways(idx+2,s,dp);
            return dp[idx]=a;
        }else{
            return dp[idx]=a;
        }
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return ways(0,s,dp);
    }
};