bool pred(int mid,int n,int m){
	    long long int num = 1;
	    while(n--){
	    	num=num*1ll*mid;
	    	if(num>=1e9) return true;
		}
	    return (num>=m);
}
int NthRoot(int n, int m){
	    // Code here.
	    // F F F F T T T T (Greater Than Prospective)
	    int lo = 0;
	    int hi = 1e5;
	    while(lo<hi){
	        int mid = (lo+hi)/2;
	       // cout<<mid<<endl;
	        if(pred(mid,n,m)){
	            hi=mid;
	        }else{
	            lo=mid+1;
	        }
	    }
	    long long int val = 1;
	    while(n--) val=val*1ll*hi;
	    if(val==m) return hi;
	    return -1;
}