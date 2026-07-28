class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mp;

        mp[1] = "I";
        mp[4] = "IV";       // CHANGED
        mp[5] = "V";
        mp[9] = "IX";       // CHANGED
        mp[10] = "X";
        mp[40] = "XL";      // CHANGED
        mp[50] = "L";
        mp[90] = "XC";      // CHANGED
        mp[100] = "C";
        mp[400] = "CD";     // CHANGED
        mp[500] = "D";
        mp[900] = "CM";     // CHANGED
        mp[1000] = "M";

        vector<int> vec;
        vec.push_back(1000);
        vec.push_back(900);
        vec.push_back(500);
        vec.push_back(400);
        vec.push_back(100);
        vec.push_back(90);
        vec.push_back(50);
        vec.push_back(40);
        vec.push_back(10);
        vec.push_back(9);
        vec.push_back(5);
        vec.push_back(4);
        vec.push_back(1);


        string ans="";
        for(int i=0;i<vec.size();i++){
            int before=num/vec[i];
            num%=vec[i];
            while(before) {
                ans += mp[vec[i]];
                before--;
            }

            if(num == 0) break;
        }
        return ans;
    }
};