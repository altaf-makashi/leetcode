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
    bool isPalindrome(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int mid=(count+1)/2;
        temp=head;
        ListNode* prev=NULL;
        while(mid--){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        ListNode* left=prev;
        if(count%2!=0)left=prev->next;
        ListNode* right=temp;
        while(left!=NULL && right!=NULL){
            if(left->val!=right->val)return false;
            left=left->next;
            right=right->next;
        }
        return true;
    }
};