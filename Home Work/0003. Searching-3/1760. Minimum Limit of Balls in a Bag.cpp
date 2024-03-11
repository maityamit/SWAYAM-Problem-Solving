class Solution {
public:
    bool pred(int mid,vector<int> &nums,int ma){
        int cnt = 0;
        for(auto it:nums) if(it>mid) cnt+=((it/mid)-(it%mid==0));
        return cnt<=ma;
    }
    int minimumSize(vector<int>& nums, int ma) {
        int lo = 1;
        int hi = 1;
        for(auto it:nums) hi=max(hi,it);
        // F F F T T T
        while(lo<hi){
            int mid = (hi+lo)/2;
            if(pred(mid,nums,ma)){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }
        return hi;
    }
};