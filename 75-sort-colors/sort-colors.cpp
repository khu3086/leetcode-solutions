class Solution {
public:
    void printarr(vector<int>& nums){
        for(auto x: nums){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    void sortColors(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        int n=nums.size();
        if(n<=1) return;
        int curr=0;
        while(curr<=high){
            if(nums[curr]==2){
                swap(nums[curr], nums[high]);
                //cout<<"swapped"<<nums[curr]<<"&"<<nums[high]<<endl;
                high--;
            }
            else if(nums[curr]==1){
                curr++;
                //cout<<"kuch ni bc"<<endl;
            }
            else{
                swap(nums[curr], nums[low]);
                //cout<<"swapped"<<nums[curr]<<"&"<<nums[low]<<endl;
                low++;
                curr++;
            }
            //printarr(nums);
        }
    }
};