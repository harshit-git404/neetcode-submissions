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
        ListNode* curr=head;
        set<ListNode*> s;
        while(curr){
            if(s.count(curr)==0) s.insert(curr);
            else return true;
            curr=curr->next;
        }
        return false;
    }
};