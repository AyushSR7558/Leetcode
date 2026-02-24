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
    int helper(string st, TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        
        if(root -> left == nullptr && root -> right == nullptr) {
            st.push_back(root -> val + '0');
            return stoi(st, nullptr, 2);
        }

        st.push_back(((root -> val) + '0'));
        return helper(st, root -> left) + helper(st, root -> right);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        string st;
        return helper("", root);
    }
};