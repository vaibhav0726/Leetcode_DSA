class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *nextNode, *prev = NULL;
        while (slow) {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        int maximumSum = 0;
        ListNode* start = head;
        while (prev) {
            maximumSum = max(maximumSum, start->val + prev->val);
            prev = prev->next;
            start = start->next;
        }

        return maximumSum;
    }
};