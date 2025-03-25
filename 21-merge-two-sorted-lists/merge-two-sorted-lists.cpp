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
        ListNode* ans = new ListNode(-101);
        ListNode* temp = ans;
        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1 != NULL && l2 != NULL){
            if(l1 -> val >= l2 -> val){
                temp -> next = new ListNode(l2 ->val);
                l2 = l2 -> next;
            }else{
                temp -> next = new ListNode(l1 -> val);
                l1 = l1 -> next;
            }
            temp = temp -> next;
        }
        while(l1 != NULL){
            temp -> next= new ListNode(l1 -> val);
            l1 = l1 -> next;
            temp = temp -> next;
        }
        while(l2 != NULL){
            temp -> next = new ListNode(l2 -> val);
            l2 = l2 -> next;
            temp = temp -> next;
        }
        // delete temp;
        // temp = ans;
        // ans = ans -> next;
        // delete temp;
        return ans -> next;
    }
};