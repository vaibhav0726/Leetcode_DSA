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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        ListNode* note = NULL;
        while(fast != NULL && fast -> next != NULL){
            // cout<<"Yes";
            slow = slow -> next;
            fast = fast -> next;
            if(fast != NULL)
                fast = fast -> next;
            if(slow == fast){
                note = slow;
                break;
            }
        }
        slow = head;
        while(note != NULL && slow != note){
            slow = slow -> next;
            note = note -> next;
        }
        if(slow == note) return slow;
        else return NULL;
    }
};