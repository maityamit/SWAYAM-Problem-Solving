class Solution {
public:
    void dfs(int r,int c,vector<vector<bool>> &vis,vector<vector<char>>& board){
        vis[r][c]=true;
        int n = board.size();
        int m = board[0].size();
        int delR[] = {-1,1,0,0};
        int delC[] = {0,0,1,-1};
        for(int i=0;i<4;i++){
            int nr = r+delR[i];
            int nc = c+delC[i];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&!vis[nr][nc]&&board[nr][nc]=='O'){
                dfs(nr,nc,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<m;i++) if(board[0][i]=='O') dfs(0,i,vis,board);
        for(int i=0;i<m;i++) if(board[n-1][i]=='O') dfs(n-1,i,vis,board);
        for(int i=0;i<n;i++) if(board[i][0]=='O') dfs(i,0,vis,board);
        for(int i=0;i<n;i++) if(board[i][m-1]=='O') dfs(i,m-1,vis,board);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};