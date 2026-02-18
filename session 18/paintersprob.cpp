class Solution {
public:
    bool possible(vector<int>& arr, int k, long long mid){
        int painters = 1;
        long long sum = 0;
        for(int board : arr){
            if(sum + board <= mid){
                sum += board;
            }else{
                painters++;
                sum = board;
                if(painters > k) return false;
            }
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        while(low < high){
            long long mid = (low + high) / 2;
            if(possible(arr, k, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
