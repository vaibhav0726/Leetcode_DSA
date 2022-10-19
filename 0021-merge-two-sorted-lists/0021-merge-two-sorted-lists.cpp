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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* temp1 = list1, *temp2 = list2;
        ListNode* ans = list1;
        if(list1 -> val > list2->val){
            ans = list2;
            list2 = list2 -> next;
        }
        else{
            ans = list1;
            list1 = list1 -> next;
        }
        ListNode* curr = ans;
        while(list1 != NULL && list2!= NULL){
            if(list1->val > list2->val){
                curr -> next = list2;
                list2 = list2 -> next;
            }
            else{
                curr -> next = list1;
                list1 = list1 -> next;
            }
            curr = curr -> next;
        }
        if(list1 != NULL)
            curr -> next = list1;
        else 
            curr -> next = list2;
        return ans;
    }
};