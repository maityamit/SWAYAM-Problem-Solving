class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int id1 = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(id1==nums.size()||nums[id1]!=target) return {-1,-1};
        int id2 = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {id1,id2-1};
    }
};