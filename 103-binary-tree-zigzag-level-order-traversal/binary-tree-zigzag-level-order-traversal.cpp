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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> mp;
        vector<vector<int>>ans;
        if(root != NULL){
            mp.push(root);
        }
        int flag = 1;
        while(!mp.empty()){
            int a = mp.size();
            vector<int>tempVec;
            for(int i = 0; i < a; i++){
                TreeNode* temp = mp.front();
                mp.pop();
                if(temp -> left != NULL){
                    mp.push(temp -> left);
                }
                if(temp -> right != NULL){
                    mp.push(temp -> right);
                }
                tempVec.push_back(temp -> val);
            }
            if(flag % 2){
                ans.push_back(tempVec);
            }else{
                reverse(tempVec.begin(),tempVec.end());
                ans.push_back(tempVec);
            }
            flag++;
        }
        return ans;
    }
};