class Solution {
bool predicate(int mid,vector<int> &arr,int X){
        int left = 0;
        int sum = 0;
        for(int i=0;i<mid;i++){
            sum+=arr[i];
        }
        if(sum>X) return false;
        for(int i=mid;i<arr.size();i++){
            sum+=arr[i];
            sum-=arr[left++];
            if(sum>X) return false;
        }
        return true;
}
int subArraySum(vector<int> &arr,int X) {
        // tttttfffff
        int lo = 0;
        int hi = arr.size();
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(predicate(mid,arr,X)){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        if(predicate(lo,arr,X)) return lo;
        else return lo-1;
}