long long int countPainters(vector<int> &arr, int n, long long int time){
    long long int  painters = 1;
    long long int total_time = 0;
    
    for(int i = 0; i < n; i++){
        // Check if the current board can be assigned to the current painter.
        if(total_time + arr[i] <= time){
            total_time += arr[i];
        }
        else{
            // Assign the current board to the next painter.
            painters++;
            total_time = arr[i];
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &arr, int k)
{
    //    Write your code here.
        long long int low = 0;
        for(auto it:arr) low=max(low,(long long int)it);
        long long int high = 1e9;
        long long int ans = low;
        
        while(low <= high){
            long long int mid = low + (high - low)/2;
            long long int painters = countPainters(arr,arr.size(),mid);
            
            if(painters > k){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
      return (int)ans; 
}