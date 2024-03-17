void solve(){

    

   int n,m,k; cin>>n>>m>>k;
   vector<int> a(n),b(m);
   forn(i,n) cin>>a[i];
   forn(i,m) cin>>b[i];

   vector<int> prefA(n+1,0),prefB(m,0);
   int sum = 0;
   forn(i,n) sum+=a[i],prefA[i+1]=sum;
   sum=0;
   forn(i,m) sum+=b[i],prefB[i]=sum;
   int maxi = 0;
   forn(i,n+1){
     int target = k-prefA[i];
     if(target>=0){
        int lb = lower_bound(prefB.begin(),prefB.end(),target)-prefB.begin();
        if(prefB[lb]==target){
            maxi=max(maxi,(i+lb+1));
        }else{
            maxi=max(maxi,(i+lb));
        }
     }
   }

   cout<<maxi;
    
}