// Lower Bound
int lowerBound(int arr[], int n, int target){
    int low = 0;
    int high = n-1;
    int ans = n; 
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1; 
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

// Upper Bound
int upperBound(int arr[], int n, int target){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}
