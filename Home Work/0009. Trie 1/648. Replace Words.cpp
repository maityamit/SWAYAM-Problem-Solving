
class Solution {
public:
    string replaceWords(vector<string>& dict, string sen) {
        string ans = "";
        unordered_map<string,int> mp;
        for(auto it:dict) mp[it]++;
        
            int idx = 0;
            while(idx<sen.size()){
                string temp = "";
                bool flag = false;
                while(idx<sen.size() && sen[idx]!=' '){
                    temp+=sen[idx++];
                    if(mp.count(temp)){
                       ans+=temp;
                       flag=true;
                       break;
                    }
                    
                }
                if(flag==false){
                   ans+=temp;
                }
                while(idx<sen.size()&&sen[idx]!=' ') idx++;
                while(idx<sen.size()&&sen[idx]==' ') ans+=sen[idx++];
            }
        return ans;
    }
};