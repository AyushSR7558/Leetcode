/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        int mini = min(p -> val, q -> val), maxi = max(p -> val, q -> val);
        while(temp != NULL){
            int NodeVal = temp -> val;
            if(NodeVal > maxi){
                temp = temp -> left;
            }else if(maxi > NodeVal && mini > NodeVal){
                temp = temp -> right;
            }else{
                return temp;
            }
        }
        return NULL;
    }
};