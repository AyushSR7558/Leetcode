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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;

        while(fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
                if(slow == fast) {
                // Phase 2: Find cycle start
                ListNode* entry = head;

                while(entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }

                return entry;  
            }
        }
        return nullptr;
    }
};