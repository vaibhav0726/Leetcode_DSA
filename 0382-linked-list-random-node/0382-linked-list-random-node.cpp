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
    ListNode* head;
    Solution(ListNode* head) {
        this -> head = head; 
    }
    
    int giveHeight(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head -> next;
        }
        return count;
    }
    
    int getRandom() {
        ListNode* temp = head;
        int n = giveHeight(temp);
        temp = head;
        int ran = rand() % n;
        while(ran--){
            temp = temp -> next;
        }
        return temp -> val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */