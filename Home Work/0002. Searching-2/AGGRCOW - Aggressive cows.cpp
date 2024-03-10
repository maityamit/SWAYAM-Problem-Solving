bool predicate(int mid,vector<int>& arr,int k){
   int cnt = 1;
   int i = 0;
   int j = 1;
   while(j<arr.size()){
   	if(arr[j]-arr[i] >= mid){
   		if(++cnt==k) return true;
   		i=j;
   	}
   	j++;
   }
   return false;
}
 
void solve(){	
   
   int n,k; cin>>n>>k;
   vector<int> arr(n);
   forn(i,n) cin>>arr[i];
   sort(all(arr));
   
 
   int lo = 0;
   int hi = 1e9;
   int ans = 0;
   while(lo<=hi){
   	int mid = (lo+hi)/2;
   	if(predicate(mid,arr,k)){
   		lo=mid+1;
   		ans=mid;
   	}else{
   		hi=mid-1;
   	}
   }
 
   cout<<ans<<endl;
 
}
 