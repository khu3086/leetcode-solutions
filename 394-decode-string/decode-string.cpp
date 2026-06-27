class Solution {
public:
    string helper(string &s, int &i) {
        string ans = "";

        while (i < s.size() && s[i] != ']') {

            if (isalpha(s[i])) {
                ans += s[i];
                i++;
            }
            else if (isdigit(s[i])) {

                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                i++; // skip '['

                string temp = helper(s, i);

                i++; // skip ']'

                while (num--)
                    ans += temp;
            }
        }

        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }
};