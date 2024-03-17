bool predicate(int a,int b,int c,int mid,int n){
	int ans ((mid/a)+(mid/b)+(mid/c)-
		(mid/((a*b)/__gcd(a,b)))-(mid/((b*c)/__gcd(b,c)))-(mid/((a*c)/__gcd(a,c)))
		+(mid/((a*b*b)/__gcd(a,__gcd(b,c)))));
	return ans<n;
}

int helper(){
	int lo = 0;
	int hi = 1e9;

	//fffffffffffftttttt
	while(lo<hi){
		int mid=(lo+hi)/2;
		if(predicate(a,b,c,mid,n)) lo=mid+1;
		else hi=mid;
	}
	return lo;
}