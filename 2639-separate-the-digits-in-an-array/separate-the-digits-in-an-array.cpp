class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int start=0;
        for(auto num: nums){
            int last=start;
            while(num!=0){
                ans.push_back(num%10);
                num/=10;
                last++;
            }
            reverse(ans.begin()+start, ans.begin()+last);
            start=last;
        }
        return ans;
    }
};