// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node 
// from the beginning and the kth node from the end (the list is 1-indexed).

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
            if(count == k){
                temp1 = temp;
            }
            if(count == len-k+1){
                temp2 = temp; 
            }
            count += 1;
            temp = temp -> next;
        }
        int t1 = temp1 -> val;
        temp1 -> val = temp2 -> val;
        temp2 -> val = t1;
        
        return head; 
    }
};