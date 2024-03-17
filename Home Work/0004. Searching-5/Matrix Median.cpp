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
int Solution::findMedian(vector<vector<int> > &A) {
    int len = A.size()*A[0].size();
    return helper(A,len/2);
}
