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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* curr=head;
        ListNode* prev=nullptr;
        int m=0;
        while(curr){
            curr=curr->next;
            m++;
        }
        m=m-n;
        if(m==0) return head->next;
        curr=head;
        while(m){
            m--;
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        return head;
    }
};