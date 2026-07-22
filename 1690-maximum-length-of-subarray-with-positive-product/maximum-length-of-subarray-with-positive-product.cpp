class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos=0;
        int neg=0;
        int ans=0;
        for(auto num: nums){
            if(num>0){
                pos++;
                if(neg!=0) neg++;
            }
            else if(num<0){
                swap(pos, neg);
                if(pos!=0) pos++;
                neg++;
            }
            else{
                pos=0;
                neg=0;
            }
            ans=max(ans, pos);
        }
        return ans;
    }
};