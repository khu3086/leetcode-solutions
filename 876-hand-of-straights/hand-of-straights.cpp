class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int num : hand) freq[num]++;

        while (!freq.empty()) {
            int card = freq.begin()->first;
            int count = freq.begin()->second;

            for (int i = 0; i < groupSize; i++) {
                int curr = card + i;

                if (freq[curr] < count) return false;

                freq[curr] -= count;
                if (freq[curr] == 0) freq.erase(curr);
            }
        }

        return true;
    }
};