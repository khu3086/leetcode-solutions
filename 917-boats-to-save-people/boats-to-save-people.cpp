class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n=people.size();
        int left=0, right=n-1;
        int boat=0;
        while(left<=right){
            int tgt=people[left]+people[right]; //max ppl
            if(tgt>limit){
                boat++;
                right--;
            }
            else{
                boat++;
                left++;
                right--;
            }
        }
        return boat;
    }
};