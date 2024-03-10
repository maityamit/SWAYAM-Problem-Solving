void solve(){
    takearrandk
    sort(all(arr));
    while(k--){
        int x; cin>>x;
        int idx = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        cout<<n-idx<<endl;
    }
}


