class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return n;
        if(n==1) return nums[0];
        int curr=nums[0];
        int vote=0;
        for(auto x: nums){
            if(curr==x) vote++;
            else{
                if(vote<=0) {curr=x; vote=0;}
                else vote--;
            }
        }
        cout<<vote;
        return curr;
    }
};