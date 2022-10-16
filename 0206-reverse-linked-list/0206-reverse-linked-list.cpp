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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* head2 = head;
        while(head2 != NULL && head2 -> next !=NULL){
            ListNode* temp = head2 -> next;
            head2 -> next = prev;
            prev = head2;
            head2 = temp;
        }
        if(head2!= NULL)
        head2 -> next = prev;
        return head2;
    }
};