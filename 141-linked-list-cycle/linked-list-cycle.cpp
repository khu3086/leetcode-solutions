/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head->next) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        int pos=-1;
        do{
            if(slow->next) slow=slow->next;
            else return false;
            if(fast&&fast->next)fast=fast->next->next;
            else return false;
        }while(slow!=fast);
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};