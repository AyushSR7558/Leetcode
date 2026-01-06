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
    int maxLevelSum(TreeNode* root) {
        int maxSum = root -> val , level = 1, indx = 1;
        queue<TreeNode*> pq;
        pq.push(root);

        while(!pq.empty()) {
            int currLevelNode = pq.size(), currSum = 0;
            for(int i = 0; i < currLevelNode; i++) {
                TreeNode* temp = pq.front();
                pq.pop();
                if(temp -> left) {
                    pq.push(temp -> left);
                }
                if(temp -> right) {
                    pq.push(temp -> right);
                }
                currSum += temp -> val;
            }
            if(currSum > maxSum) {
                maxSum = currSum;
                level = indx;
            }
            indx++;
        }
        return level;
    }
};