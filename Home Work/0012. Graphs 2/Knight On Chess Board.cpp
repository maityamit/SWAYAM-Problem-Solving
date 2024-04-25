int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    C--;
    D--;
    E--;
    F--;
    
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{C,D}});
    vector<vector<bool>> vis(A,vector<bool>(B,false));
    vis[C][D]=true;
    while(q.size()!=0){
        auto it = q.front(); q.pop();
        
        if(it.second.first==E && it.second.second==F) return it.first;
        
        int delX[] = {-2,-1,2,1,-2,2,-1,1};
        int delY[] = {1,2,-1,-2,-1,1,-2,2};
        
        for(int m=0;m<8;m++){
           int nr = delX[m]+it.second.first;
           int nc = delY[m]+it.second.second;
           if(nr>=0 && nc>=0 && nr<A && nc<B && vis[nr][nc]==false){
              vis[nr][nc]=true;
              q.push({it.first+1,{nr,nc}});
           }
        }
    }
    return -1;
}
