class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        int ans = 0;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        
        priority_queue <pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        
        while(pq.size()!=0){
            int wt = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if(r==n-1 && c==m-1){
                if(ans==0) ans=wt;
                else ans = min(ans,wt);
            }
            
            int delR[] = {-1,0,+1,0};
            int delC[] = {0,-1,0,+1};
            
            for(int i=0;i<4;i++){
                int nr = delR[i]+r;
                int nc = delC[i]+c;
                
                if(nr>=0&&nc>=0&&nr<n&&nc<m){
                    int dis = abs(heights[nr][nc] - heights[r][c]);
                    // dis = max(dis,wt);
                    if(dis < dist[nr][nc]){
                        dist[nr][nc] = dis;
                        pq.push({max(dis,wt),{nr,nc}});
                    }
                    
                }
                
            }
            
        }
        
        return ans;
    }
};