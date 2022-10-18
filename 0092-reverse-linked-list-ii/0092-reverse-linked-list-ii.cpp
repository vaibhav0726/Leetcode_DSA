class Solution {
private:
    ListNode* reverse(ListNode* head){
        if(head == NULL){
            return NULL;
        }
        ListNode* temp = head, *prev = NULL;
        while(temp!=NULL){
            ListNode* temp2 = temp->next;
            temp -> next = prev;
            prev = temp;
            temp = temp2;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* curr = head, *prev = NULL;
        int count = 1;
        while(count != left){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        ListNode* start = curr; // 2
        while(count != right){
            curr = curr-> next;
            count++;
        }
        ListNode* nxt = curr->next;
        curr -> next = NULL;
        cout<<curr->val;
        ListNode* newHead = reverse(start);
        if(prev != NULL)
            prev -> next = newHead;
        curr = newHead;
        while(curr->next != NULL){
            curr = curr -> next;
        }
        curr -> next = nxt;
        if(left == 1) return newHead;
        else return head;
    }
};