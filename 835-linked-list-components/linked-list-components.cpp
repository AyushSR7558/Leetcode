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
    bool isPresent(vector<int>& nums, int val) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == val)
                return true;
        }
        return false;
    }

public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int count = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            if (isPresent(nums, temp->val)) {
                count++;
                while (temp != nullptr && isPresent(nums, temp->val)) {
                    temp = temp -> next;
                }
                continue;
            }
            temp = temp -> next;
        }
        return count;
    }
};