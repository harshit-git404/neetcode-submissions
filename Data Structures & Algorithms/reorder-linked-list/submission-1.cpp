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
        ListNode* slow=head;
        ListNode* fast=head->next;  //to get slow at 1st middle
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr=slow->next;    //reversing 2nd half of list
        ListNode* prev=nullptr;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        slow->next=nullptr;   //this still points to next node of old chain, now points to null as it's the last one of new chain

        ListNode* first=head;
        ListNode* second=prev;
        while(second){ //not checking first, last (second->next) will point to last node of 1st
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};