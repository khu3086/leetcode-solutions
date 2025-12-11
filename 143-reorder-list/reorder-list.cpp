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
    void reorderList(ListNode* head) {
        vector<ListNode*> myNodeList;
        ListNode* curr=head;
        while(curr){
            myNodeList.push_back(curr);
            curr=curr->next;
        }
        int n=myNodeList.size();
        int left=0, right=n-1;
        while(left<right-1){
            ListNode* currLeft= myNodeList[left];
            ListNode* currRight= myNodeList[right];
            currLeft->next=currRight;
            currRight->next=myNodeList[++left];
            right--;
        }
        myNodeList[right]->next=nullptr;
        
    }
};