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
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || !head->next || k == 0) return head;  // ✅ edge cases
        ListNode* curr=head;
        int n = 1;
        while(curr->next){
            n++;
            curr=curr->next;
        }
        k=k%n;
        if(k==0) return head;
        curr=head;
        int num=n-k-1;
        while(num){
            curr=curr->next;
            num--;
        }
        ListNode* newHead=curr->next;
        ListNode* breakNode=curr;
        curr=head;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=head;
        curr=head;
        while(curr!=breakNode){
            curr=curr->next;
        }
        curr->next=nullptr;
        return newHead;
    }
};