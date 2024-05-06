class Solution {
public:
    int dp[201][201];
    int helper(int x,int y,vector<vector<int>>& dung){
        if(x==dung.size()-1&&y==dung[0].size()-1){
            if(dung[x][y]<=0) return 1-dung[x][y];
            else return 1;
        }
        if(x>=dung.size()||y>=dung[0].size()) return 1e9;
        if(dp[x][y]!=-1) return dp[x][y];
        int amit = min(helper(x+1,y,dung),helper(x,y+1,dung))-dung[x][y];
        if(amit<=0) return dp[x][y]=1;
        else return dp[x][y]=amit;
    }
    int calculateMinimumHP(vector<vector<int>>& dung) {
        for(int i=0;i<=200;i++) for(int j=0;j<=200;j++) dp[i][j]=-1;
        return helper(0,0,dung);
    }
};