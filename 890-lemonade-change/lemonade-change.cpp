class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> map;
        for(auto x: bills){
            if(x==5){
                map[x]++;
            }
            else if(x==10){
                if(map[5]>0){
                    map[x]++;
                    map[5]--;
                }
                else return false;
            }
            else{
                if(map[5]>0&&map[10]>0){
                    map[20]++;
                    map[10]--;
                    map[5]--;
                }
                else if(map[5]>2){
                    map[5]-=3;
                    map[20]++;
                }
                else return false;
            }
        }
        return true;
    }
};