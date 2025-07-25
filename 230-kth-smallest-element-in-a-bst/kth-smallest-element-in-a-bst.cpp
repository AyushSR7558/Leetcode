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
private:
    int inOrder(TreeNode* root, int k) {
    int count = 0;
    vector<int> ans;
    stack<TreeNode*> s;
    TreeNode* curr = root;

    while (curr != nullptr || s.empty() == false) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        count++;
        if(count == k){
            return curr -> val;
        }
        curr = curr->right;
    }
    
    return -1;
}
public:
    int kthSmallest(TreeNode* root, int k) {
        return inOrder(root,k);
    }
};