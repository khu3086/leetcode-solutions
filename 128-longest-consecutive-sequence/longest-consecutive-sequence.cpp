class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto x: nums) mp.insert(x);
        int currlen=0;
        int maxlen=0;
        for(auto x: mp){//iterate set not nums
            // only start counting if x is the start of a sequence
            if (mp.find(x - 1) == mp.end()) {
                int s = x;
                while (mp.find(x) != mp.end()) {
                    x++;
                }
                int currlen = x - s;
                maxlen = max(maxlen, currlen);
            }
        }
        return maxlen;
    }
};