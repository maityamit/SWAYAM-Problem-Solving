class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Time Complexity: O(m+n)
        // int st = matrix[0].size()-1;
        // int en = 0;
        // while(en<matrix.size() && st>=0){
        //     if(matrix[en][st]==target) return true;
        //     if(matrix[en][st]>target) st--;
        //     else en++;
        // }
        // return false;
        
        // Treat this an array
        int lo = 0;
        int hi = (matrix.size()*matrix[0].size())-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]==target) return true;
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]>target) hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};