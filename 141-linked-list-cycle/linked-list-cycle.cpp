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
            slow=slow->next;
            if(fast->next)fast=fast->next->next;
        }while(slow&&fast&&slow!=fast);
        if(slow==nullptr) return false;
        if(fast==nullptr||fast->next==nullptr) return false;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};