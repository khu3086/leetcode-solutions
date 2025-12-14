/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* prev1=nullptr;
        ListNode* prev2=nullptr;
        while(curr1&&curr2){
            curr1->val+=curr2->val;
            curr1->val+=carry;
            carry=curr1->val/10;
            curr1->val%=10;
            prev1=curr1;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        while(curr1){
            curr1->val+=carry;
            carry=curr1->val/10;
            curr1->val%=10;
            prev2=curr1;
            curr1=curr1->next;
        }
        if(curr2){
            if (prev1) prev1->next = curr2;
            curr1=curr2;
            while(curr1){
            curr1->val+=carry;
            carry=curr1->val/10;
            curr1->val%=10;
            prev2=curr1;
            curr1=curr1->next;
        }
        }
        if (carry != 0) {                     // ✅ create only if needed
            if (prev2) prev2->next = new ListNode(carry);
            else prev1->next = new ListNode(carry);
        }

        return l1;
    }
};