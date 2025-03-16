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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* Re = head;
        if(Re == NULL){
            return NULL;
        }
        //I will traverse through the whole list while traversing through whole list i will look after the data which is present in the Node if the data of the adjacent node is same then i will remove the nobe and go forward this is my plan now i will flow it
        while(head != NULL && head -> next != NULL){
            if(head -> val == head -> next -> val){
                ListNode* temp = head -> next -> next;
                delete head -> next;
                head -> next = temp;
                continue;
            }
            head = head -> next;
        }
        return Re;
    }
};