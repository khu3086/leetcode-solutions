class Solution {
public:
    long long numberOfWays(string s) {
        unordered_map<string, long long> mp;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                mp[string(1, s[i])]++;
                if(mp.find("1")!=mp.end()){
                    mp["10"]+=mp["1"];
                }
                if(mp.find("01")!=mp.end()){
                    mp["010"]+=mp["01"];
                }
            }
            if(s[i]=='1'){
                mp[string(1, s[i])]++;
                if(mp.find("0")!=mp.end()){
                    mp["01"]+=mp["0"];
                }
                if(mp.find("10")!=mp.end()){
                    mp["101"]+=mp["10"];
                }
            }
        }
        long long sum=0;
        if(mp.find("101")!=mp.end()) sum+=mp["101"];
        if(mp.find("010")!=mp.end()) sum+=mp["010"];
        return sum;
    }
};