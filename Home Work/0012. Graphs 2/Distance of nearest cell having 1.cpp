class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    void bfs(vector<vector<int>> &grid,vector<vector<bool>> &vis){
        queue<pair<pair<int,int>,int>> pending;
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    pending.push({{i,j},0});
                    vis[i][j]=true;
                    grid[i][j]=0;
                }
            }
        }
        
        while(pending.size()!=0){
            int row=pending.front().first.first;
            int col=pending.front().first.second;
            int level=pending.front().second;
            pending.pop();
            
            int delRow[]={-1,0,+1,0};
            int delCol[]={0,+1,0,-1};
            
            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&
                   grid[nrow][ncol]==0 && !vis[nrow][ncol]){
                       vis[nrow][ncol]=true;
                       grid[nrow][ncol]=level+1;
                       pending.push({{nrow,ncol},level+1});
                   }
                
            }
            
        }
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
        int m=grid[0].size();
	    vector<vector<bool>> vis(n,vector<bool>(m,false));
	    bfs(grid,vis);
	    return grid;
	}
};