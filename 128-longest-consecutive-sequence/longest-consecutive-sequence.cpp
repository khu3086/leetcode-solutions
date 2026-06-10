class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxlen=0;
        for(auto num: st){
            int len=1;
            int curr=num;
            if(st.find(num-1)==st.end()){
                while(st.find(curr+1)!=st.end()){
                    len++;
                    curr++;
                }
                maxlen=max(maxlen, len);
            }
        }
        return maxlen;
    }
};