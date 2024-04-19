class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        
        vector<vector<int>> arr = {{0,+1,0,-1,1,3,5,1,4,6},{+1,0,-1,0,2,5,6,2,3,4},
                                   {0,-1,+1,0,1,4,6,2,5,6},{0,+1,+1,0,1,3,5,2,5,6},
                                   {-1,0,0,-1,2,3,4,1,4,6},{-1,0,0,+1,2,3,4,1,3,5}};
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;
        while(q.size()!=0){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==n-1 && y==m-1) return true;
            
            
            vector<int> it = arr[grid[x][y]-1];
            int nrx1=x+it[0]; int nry1=y+it[1];
            if(nrx1>=0&&nry1>=0&&nrx1<n&&nry1<m&&!vis[nrx1][nry1]&&
               (grid[nrx1][nry1]==it[4]||grid[nrx1][nry1]==it[5]||grid[nrx1][nry1]==it[6])){
                vis[nrx1][nry1]=true;
                q.push({nrx1,nry1});
            }
             
            int nrx2=x+it[2]; int nry2=y+it[3];
            if(nrx2>=0&&nry2>=0&&nrx2<n&&nry2<m&&!vis[nrx2][nry2]&&
               (grid[nrx2][nry2]==it[7]||grid[nrx2][nry2]==it[8]||grid[nrx2][nry2]==it[9])){
                vis[nrx2][nry2]=true;
                q.push({nrx2,nry2});
            }
            
        }
        
        return false;
    }
};