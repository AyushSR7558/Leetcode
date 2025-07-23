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
int maxDiameter = 0;

int heightAndUpdateDiameter(TreeNode* root) {
    if (root == NULL) return 0;
    int leftHeight = heightAndUpdateDiameter(root->left);
    int rightHeight = heightAndUpdateDiameter(root->right);
    maxDiameter = max(maxDiameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        heightAndUpdateDiameter(root);
        return maxDiameter;
    }
};