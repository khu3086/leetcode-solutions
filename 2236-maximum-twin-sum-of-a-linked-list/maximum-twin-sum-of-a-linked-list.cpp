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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* middle=slow;
        ListNode* curr=slow;
        ListNode* prev=nullptr;
        while(curr){
            // ListNode* temp=curr->next;
            // curr->next=prev;
            // prev=curr;
            // curr=temp;
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        //prev is new head
        int sum=0;
        ListNode* start=head;
        ListNode* end=prev;
        while(end){
            sum=max(start->val+end->val, sum);
            start=start->next;
            end=end->next;
        }
        return sum;
    }
};