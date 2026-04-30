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
    int count_Nodes(ListNode* head){
        int count=1;
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            count+=2;
            temp=temp->next->next;
        }
        if(temp==NULL)count--;
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || (head->next==NULL && n==1))
            return NULL;
        int count=count_Nodes(head);
        int del=count-n;
        if(del==0)return head->next;
        ListNode* temp=head;
        while(--del){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};