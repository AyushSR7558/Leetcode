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
    int maxDepth(TreeNode* root) {
         if (root == nullptr) return 0;  
        queue<TreeNode*>que;
        que.push(root);
        int count = 0;
        while(!que.empty()){
            int size = que.size();
            count++;
            for(int i = 0; i < size; i++){
                TreeNode* temp = que.front();
                que.pop();
                if(temp -> left != NULL){
                    que.push(temp -> left);
                }
                if(temp -> right != NULL){
                    que.push(temp -> right);
                }
            }
        }
        return count;
    }
};