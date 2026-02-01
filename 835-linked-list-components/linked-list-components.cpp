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
    int numComponents(ListNode* head, vector<int>& nums) {
        int count = 0;
        ListNode* temp = head;
        unordered_set<int> st(nums.begin(), nums.end());

        while (temp != nullptr) {
            if (st.count(temp->val)) {
                count++;
                while (temp != nullptr && st.count(temp->val)) {
                    temp = temp -> next;
                }
                continue;
            }
            temp = temp -> next;
        }
        return count;
    }
};