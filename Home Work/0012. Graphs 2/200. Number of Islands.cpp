class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j]=true;
        int delR[] = {-1,1,0,0};
        int delC[] = {0,0,-1,1};
        for(int p=0;p<4;p++){
            int nr = delR[p]+i;
            int nc = delC[p]+j;
            if(nr>=0&&nc>=0&&nr<n&&nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};