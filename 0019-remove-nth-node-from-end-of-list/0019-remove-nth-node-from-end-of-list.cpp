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
    int giveLength(ListNode* head){
        int len = 0;
        while(head != NULL){
            head = head -> next;
            len++;
        }

        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = giveLength(temp);
        if(len == 1) return NULL;
        if(len == n) return head -> next;
        temp = head;
        n = len - n - 1;
        while(temp != NULL && n--){
            temp = temp -> next;
        }
        cout<<temp->val<<endl;
        if(temp != NULL)
            temp -> next = temp -> next -> next;
        return head;
    }
};