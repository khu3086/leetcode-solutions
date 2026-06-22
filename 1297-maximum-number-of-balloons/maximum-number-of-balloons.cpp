class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int, int> balloon, textmp;
        string b="balloon";
        for(auto c: b) balloon[c]++;
        for(auto c: text) textmp[c]++;
        int mini=INT_MAX;
        for(auto it: balloon){
            if(textmp.find(it.first)==textmp.end()) return 0;
            if(balloon[it.first]>textmp[it.first]) return 0;
            else {
                mini=min(mini, textmp[it.first] / it.second);
            }
        }
        return mini;
    }
};