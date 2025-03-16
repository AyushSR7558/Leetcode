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
    ListNode* Traverse(ListNode* Head,int position){
        int i = 1;
        while(i < position){
            Head = Head -> next;
            i++;
        }
        return Head;
    }
    pair<ListNode*,ListNode*> Reverse(ListNode *Head, int k,int count){
        if(count == k){
            pair<ListNode*,ListNode*>ans;
            ans.first = Head;
            if(Head == NULL){
                ans.second = NULL;
                return ans;
            }
            ans.second = Head -> next;
            return ans;
        }
        pair<ListNode*,ListNode*>ans = Reverse(Head -> next, k, count + 1);

        Head -> next -> next = Head;
        Head -> next = NULL;
        return ans;
    }

    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode* before = Traverse(head,left - 1);
            
            ListNode* tail = before -> next;
            if(left == 1){
                tail = head;
            }

            pair<ListNode*,ListNode*> HeadAndafter = Reverse(tail,right-left,0);

            if(left != 1)
            before -> next = HeadAndafter.first;
            tail -> next = HeadAndafter.second;

            if(left == 1){
                head = HeadAndafter.first;
                return head;
            }
            return head;
        }
    };