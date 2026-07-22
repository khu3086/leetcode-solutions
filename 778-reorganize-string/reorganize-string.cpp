class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        int maxFreq=0;
        for(int i=0;i<s.length();i++) {
            freq[s[i]]++; 
            maxFreq=max(maxFreq, freq[s[i]]);
        }
        priority_queue<pair<int, char>> maxheap;
        for(auto m: freq){
            maxheap.push({m.second, m.first});
        }
        string res="";
        while(maxheap.size()>=2){
            auto [freq1, char1]=maxheap.top(); maxheap.pop();
            auto [freq2, char2]=maxheap.top(); maxheap.pop();
            res+=char1;
            res+=char2;
            if(--freq1>0) maxheap.push({freq1, char1});
            if(--freq2>0) maxheap.push({freq2, char2});
        }
        if(!maxheap.empty()){
            auto [freq, c]=maxheap.top(); 
            if(freq>1) return "";
            res+=c;
        }
        return res;
        
    }
};