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
    vector<int> inOrderTraversal(TreeNode* root){
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* temp = root;
        while(temp != NULL || !st.empty()){
            while(temp != NULL){
                st.push(temp);
                temp = temp -> left;
            }
            temp = st.top();
            st.pop();
            ans.push_back(temp -> val);
            temp = temp -> right;
        }
        return ans;
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inOrderVec = inOrderTraversal(root);
        for(int i = 1; i < inOrderVec.size(); i++){
            if(inOrderVec[i - 1] > inOrderVec[i] || inOrderVec[i - 1] == inOrderVec[i]){
                return false;
            }
        }
        return true;
    }
};