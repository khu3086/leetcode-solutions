class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(auto num: arr1){
            int temp=num;
            while(temp){
                st.insert(temp);
                temp/=10;
            }
        }
        int maxLen = 0;

        // Check prefixes in arr2
        for (auto num : arr2) {
            int temp = num;
            while (temp) {
                if (st.count(temp)) {
                    int len = 0;
                    int t = temp;
                    while (t) {
                        len++;
                        t /= 10;
                    }
                    maxLen = max(maxLen, len);
                }
                temp /= 10;
            }
        }

        return maxLen;
    }
};