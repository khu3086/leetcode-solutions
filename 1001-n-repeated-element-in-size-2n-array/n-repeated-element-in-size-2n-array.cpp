class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int m=nums.size();
        int n=m/2;
        vector<int> hash(100001, 0);
        for(auto x: nums){
            hash[x]++;
        }
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] == n) {
                return i;   // i is the element
            }
        }
        return 0;
    }
};