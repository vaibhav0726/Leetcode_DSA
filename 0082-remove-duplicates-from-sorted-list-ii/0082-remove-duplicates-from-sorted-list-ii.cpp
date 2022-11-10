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
    ListNode* deleteDuplicates(ListNode* head) {
        // dummy also == sentinal
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* slow = dummy;
        while(head != NULL){
            if(head -> next != NULL && head -> val == head -> next -> val){
                while(head -> next != NULL && head -> val == head->next->val){
                    head = head -> next;
                }
                slow -> next = head -> next;
            }
            else{
                slow = slow -> next;
            }
            head = head -> next;
        }
        return dummy -> next;
    }
};