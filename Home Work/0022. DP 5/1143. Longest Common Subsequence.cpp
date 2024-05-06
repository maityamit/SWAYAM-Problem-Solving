int const N = 1e3;
class Solution {
public:
    int dp[N+1][N+1];
    int helper(int i,int j,string &text1, string &text2){
        if(i==text1.size()||j==text2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j]=1+helper(i+1,j+1,text1,text2);
        }else{
            return dp[i][j]=max(helper(i+1,j,text1,text2),helper(i,j+1,text1,text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,text1,text2);
    }
};