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
    int HeightOfTree(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftHeight = HeightOfTree(root -> left);
        int rightHeight = HeightOfTree(root -> right);
        if(leftHeight == -1 || rightHeight == -1)return -1;
        if(abs(leftHeight - rightHeight) > 1)return -1;
        return 1 + max(leftHeight,rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        int ans = HeightOfTree(root);
        return (ans == -1? false: true);
    }
};