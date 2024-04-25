bool helper(int i,int j,int A, int B, vector<vector<bool>> &vis){
    if(i==A && j==B) return true;
    vis[i][j]=true;
    int delX[] = {-1,1,0,0,-1,1,-1,1};
    int delY[] = {0,0,-1,1,-1,1,1,-1};
    for(int m=0;m<8;m++){
        int nr = delX[m]+i;
        int nc = delY[m]+j;
        if(nr>=0 && nc>=0 && nr<=A && nc<=B && vis[nr][nc]==false){
            if(helper(nr,nc,A,B,vis)) return true;
        }
    }
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool>> vis(A+1,vector<bool>(B+1,false));
    for(int i=0;i<C;i++){
        
        for(int p=0;p<=A;p++){
            for(int q=0;q<=B;q++){
                float dist = (float)sqrt(pow(E[i]-p,2)+pow(F[i]-q,2));
                if(dist<=(float)D) vis[p][q]=true;
            }
        }
    }
    
    
    
    if(helper(0,0,A,B,vis)) return "YES";
    else return "NO";
}
