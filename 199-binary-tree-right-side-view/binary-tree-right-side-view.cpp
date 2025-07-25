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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root != NULL){
            q.push(root);
        }
        while(!q.empty()){
            int sizeOfQueue = q.size();
            ans.push_back(q.front() -> val);
            for(int i = 0; i < sizeOfQueue; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp -> right != NULL){
                    q.push(temp -> right);
                }
                if(temp -> left != NULL){
                    q.push(temp -> left);
                }
            }
        }
        return ans;
        
    }
};