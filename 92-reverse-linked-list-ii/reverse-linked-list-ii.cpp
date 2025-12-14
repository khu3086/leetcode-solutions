class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        int nleft = left - 1;
        int nright = right - 1;

        while (nleft) {
            prev = curr;
            curr = curr->next;
            nleft--;
        }

        ListNode* start = curr;
        ListNode* startPtr = prev;

        curr = head;
        while (nright) {
            curr = curr->next;
            nright--;
        }

        ListNode* end = curr;
        ListNode* endNext = end->next;   // ✅ SAVE BEFORE REVERSAL

        prev = nullptr;
        curr = start;

        while (curr != endNext) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        if (startPtr) startPtr->next = end;
        else head = end;

        start->next = endNext;

        return head;
    }
};
