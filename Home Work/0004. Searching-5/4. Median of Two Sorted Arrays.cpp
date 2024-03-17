class Solution {
public:
    double helper(vector<int>& nums1, vector<int>& nums2,int k){
        int lo = -1e9;
        int hi = 1e9;
        // for(auto it:nums1) lo=min(lo,it),hi=max(hi,it);
        // for(auto it:nums2) lo=min(lo,it),hi=max(hi,it);
        double ans = lo;
        
        while((hi-lo)>1){
            int mid = (lo+hi)/2;
            int countlessThanK = lower_bound(nums1.begin(),nums1.end(),mid)-nums1.begin();
            countlessThanK+= lower_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();
            
            // ttttttttttfffff
            if(countlessThanK <= k) lo = mid; 
            else hi = mid;
        }
        return lo;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       double a = helper(nums1,nums2,(nums1.size()+nums2.size())/2);
       double b = helper(nums1,nums2,((nums1.size()+nums2.size())/2)-1);
       if((nums1.size()+nums2.size())%2==1) return a;
       else return (a+b)/2;
    }
};