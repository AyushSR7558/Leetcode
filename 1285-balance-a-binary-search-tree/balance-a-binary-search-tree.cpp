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
    void inOrderTraversal(TreeNode* root, vector<int>& nums) {
        if(root == NULL) return ;

        inOrderTraversal(root -> left, nums);
        nums.push_back(root -> val);
        inOrderTraversal(root -> right, nums);
    }

    TreeNode* binarySearchTree(vector<int>& nums, int l, int r) {
        if(r < l) return nullptr;
        if(l == r) {
             TreeNode* temp = new TreeNode(nums[l]);
             return temp;
        }

        int mid = l + (r - l) / 2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp -> left = binarySearchTree(nums, l, mid - 1);
        temp -> right = binarySearchTree(nums, mid + 1, r);
        return temp;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> traversal;
        inOrderTraversal(root, traversal);

        TreeNode* temp = binarySearchTree(traversal, 0, traversal.size() - 1);

        return temp;
    }
};