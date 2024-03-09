class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int lo = 0;
	    int hi = n-1;
	    while(lo<hi){
	        int mid = (lo+hi)/2;
	        if(arr[mid]>=arr[0]){
	            lo = mid+1;
	        }else{
	            hi = mid;
	        }
	    }
	    if(hi+1==n && arr[n-2]<arr[n-1]) return 0;
	    else return hi;
	}

};