int helper(vector<vector<int>> &vec,int k){
        int lo = -1e9;
        int hi = 1e9;
        double ans = lo;
        while((hi-lo)>1){
            int mid = (lo+hi)/2;
            int countlessThanK = 0;
            for(auto &it:vec){
                countlessThanK += lower_bound(it.begin(),it.end(),mid)-it.begin();
            }
            // ttttttttttfffff
            if(countlessThanK <= k) lo = mid; 
            else hi = mid;
        }
        return lo;
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{ 
  //Your code here
  vector<vector<int>> vec(n,vector<int>(n));
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) vec[i][j]=mat[i][j];
  return helper(vec,k-1);
}
