class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> uset(nums.begin(), nums.end());
        ListNode dummy(0, head);
        ListNode* curr = &dummy;

        while (curr->next) {
            if (uset.find(curr->next->val) != uset.end()) {
                curr->next = curr->next->next;  // ✅ unlink only, no delete
            } else {
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};

