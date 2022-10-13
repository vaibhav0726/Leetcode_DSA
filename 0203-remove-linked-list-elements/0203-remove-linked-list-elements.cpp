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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL ) return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            
            if(prev == NULL && temp->val == val){
                head = head -> next;
                // temp = head;
                temp = temp -> next;
                continue;
            }
            else if(temp->val == val){
                prev->next = temp->next;
                temp = temp -> next;
                continue;
            }
            prev = temp;
            temp = temp -> next;
        }
        // if(head != NULL && head -> val == val) head = NULL; 
        return head;
    }
};