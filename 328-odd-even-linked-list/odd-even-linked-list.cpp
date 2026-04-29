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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* odd_head=head;
        ListNode* even_head=head->next;
        ListNode* odd=head;
        ListNode* even=head->next;
        // odd infin
        while((odd->next!=NULL && odd->next->next!=NULL) ||
         (even->next!=NULL && even->next->next!=NULL)){
            if(odd->next->next!=NULL){
                odd->next=odd->next->next;
                odd=odd->next;
            }
            if(even->next->next!=NULL){
                even->next=even->next->next;
                even=even->next;
            }
        }
        even->next=NULL;
        odd->next=even_head;
        return odd_head;
    }
};