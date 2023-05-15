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
    int length(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count += 1;
            temp = temp -> next;
        }
        return count;
        
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int len = length(head);
        int count = 1;
        
        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;
        
        while(count <= len){
            // count += 1;
            if(count == k){
                temp1 = temp;
            }
            if(count == len-k+1){
                temp2 = temp; 
            }
            // if(temp != NULL)
            count += 1;
                temp = temp -> next;
            
        }
        
        int t1 = temp1 -> val;
        temp1 -> val = temp2 -> val;
        temp2 -> val = t1;
        
        return head;
    }
};