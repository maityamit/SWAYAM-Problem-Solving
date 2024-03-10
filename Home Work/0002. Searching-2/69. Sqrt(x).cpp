class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = 1e9;
        while(low<=high){
            long long int mid = (low+high)/2;
            if(mid*mid > x){
                high = mid-1;
            }else{
                if((mid+1)*(mid+1) > x) return mid;
                low = mid+1;
            }
        }
        return low;
    }
};