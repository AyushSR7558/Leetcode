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
    bool isTrue(TreeNode* leftRoot, TreeNode* rightRoot){
        if(leftRoot == NULL || rightRoot == NULL){
            return (leftRoot == NULL && rightRoot == NULL);
        }
        if(leftRoot -> val != rightRoot -> val){
            return false;
        }
        return isTrue(leftRoot -> right, rightRoot -> left) && isTrue(leftRoot -> left, rightRoot -> right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isTrue(root -> left, root -> right);
    }
};