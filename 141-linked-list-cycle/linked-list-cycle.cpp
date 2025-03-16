/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> store;

        while(head != NULL){
            for(int i = 0; i < store.size(); i++){
                if(store[i] == head){
                    return 1;
                }
            }
            store.push_back(head);
            head = head -> next;
        }
        return 0;
    }
};