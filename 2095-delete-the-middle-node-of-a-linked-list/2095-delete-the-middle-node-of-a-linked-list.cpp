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
private:
    int findLen(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        return count;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        int len = findLen(head);
        if(len <= 1){
            return NULL;
        }
        len = len / 2 -1;
        ListNode* temp = head;
        while(len--){
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        return head;
    }
};