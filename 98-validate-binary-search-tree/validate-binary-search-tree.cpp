/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* temp = root;
        TreeNode* prev = nullptr;
        stack<TreeNode*> st;
        while(temp != NULL || !st.empty()){
            while(temp != NULL){
                st.push(temp);
                temp = temp -> left;
            }
            temp = st.top();
            st.pop();
            if(prev != nullptr && prev -> val >= temp -> val){
                return false;
            }
            prev = temp;
            temp = temp -> right;
        }
        return true;
    }
};