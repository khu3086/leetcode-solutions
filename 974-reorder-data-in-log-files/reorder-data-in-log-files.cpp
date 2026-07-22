class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letter;
        vector<string> digit;

        for (auto &log : logs) {
            int pos = log.find(' ');

            if (isalpha(log[pos + 1])) {
                string id = log.substr(0, pos);
                string content = log.substr(pos + 1);
                letter.push_back({content, id});
            } else {
                digit.push_back(log);
            }
        }

        sort(letter.begin(), letter.end());

        vector<string> ans;

        for (auto &p : letter) {
            ans.push_back(p.second + " " + p.first);
        }

        for (auto &d : digit) {
            ans.push_back(d);
        }

        return ans;
    }
};