class Solution {
public:
    bool predicate(int mid,string &s,string &t,int maxCost){
        int cost = 0;
        for(int i=0;i<mid;i++){
            cost+=abs(s[i]-t[i]);
        }
        if(cost<=maxCost) return true;
        int left = 0;
        for(int i=mid;i<s.size();i++){
            cost+=abs(s[i]-t[i]);
            cost-=abs(s[left]-t[left]);
            left++;
            if(cost<=maxCost) return true;
        }
        return false;
    }
    int equalSubstring(string s, string t, int maxCost) {
        // tttttfffff
        int lo = 0;
        int hi = s.size();
        cout<<predicate(1,s,t,maxCost);
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(predicate(mid,s,t,maxCost)){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        if(predicate(lo,s,t,maxCost)) return lo;
        else return lo-1;
    }
};