class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int,pair<int,int>>> pending;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) pending.push({0,{i,j}});
            }
        }
        
        while(pending.size()!=0){
            auto it = pending.front(); pending.pop();
            int wt = it.first;
            int x = it.second.first;
            int y = it.second.second;
            ans = max(ans,wt);
            int delR[] = {-1,1,0,0};
            int delC[] = {0,0,-1,1};
            for(int p=0;p<4;p++){
                int nr = delR[p]+x;
                int nc = delC[p]+y;
                if(nr>=0&&nc>=0&&nr<n&&nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    pending.push({wt+1,{nr,nc}});
                }
            }
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};