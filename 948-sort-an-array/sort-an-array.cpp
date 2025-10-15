class Solution {
public:
    void merge(vector<int>&arr, int low, int mid, int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        while(left<=mid&&right<=high){
            if(arr[left]>arr[right]) {temp.push_back(arr[right]); right++;}
            else {temp.push_back(arr[left]); left++;}
        }
        while(left<=mid) {
            temp.push_back(arr[left]); left++;
        }
        while(right<=high){
            temp.push_back(arr[right]); right++;
        }
        int i=low;
        while(i<=high) {arr[i]=temp[i-low]; i++;}
    }
    void mergesort(vector<int>& arr, int low, int high){
        if(low>=high) return;
        int mid=low+(high-low)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};