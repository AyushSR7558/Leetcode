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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        if(root == nullptr) return {};

        queue<TreeNode*> pq;
        pq.push(root);

        while(!pq.empty()) {
            int sz = pq.size();
            vector<int> level;
            for(int i = 0; i < sz; i++) {
                TreeNode* node = pq.front();
                level.push_back(node -> val);
                pq.pop();
                if(node -> left != nullptr) {
                    pq.push(node -> left);
                }
                if(node -> right != nullptr) {
                    pq.push(node -> right);
                }
            }
            traversal.push_back(level);
        }
        return traversal;
    }
};