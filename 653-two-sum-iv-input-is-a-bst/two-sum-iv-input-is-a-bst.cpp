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
    vector<int> InOrderTraversal(TreeNode* root){
        if(root == NULL) return {};
        stack<TreeNode*> st;
        vector<int>inorder;
        TreeNode* temp = root;
        while(temp || !st.empty()){
            while(temp != NULL){
                st.push(temp);
                temp = temp -> left;
            }
            temp = st.top();
            st.pop();
            inorder.push_back(temp -> val);
            temp = temp -> right;
        }
        return inorder;
    }
    bool twoSum(vector<int>& nums, int k){
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == k) return true;
            if(sum < k){
                left++;
            }else{
                right--;
            }
        }
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums = InOrderTraversal(root);
        return twoSum(nums,k);
    }
};