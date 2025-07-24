/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<tuple<TreeNode*, int, int>> qp;
        map<int, map<int, multiset<int>>> mp;
        if (root != NULL) {
            qp.push(make_tuple(root, 0, 0));
        }
        while (!qp.empty()) {
            int sizeOfQueue = qp.size();
            for (int i = 0; i < sizeOfQueue; i++) {
                tuple<TreeNode*, int, int> front = qp.front();
                qp.pop();
                if (get<0>(front)->left) {
                    qp.push(make_tuple(get<0>(front) -> left, get<1>(front) - 1,
                                         get<2>(front) + 1));
                }
                if (get<0>(front)->right) {
                    qp.push(make_tuple(get<0>(front) -> right, get<1>(front) + 1,
                                         get<2>(front) + 1));
                }
                mp[get<1>(front)][get<2>(front)].insert(get<0>(front)->val);
            }
        }
        vector<vector<int>> ans;
        for (auto& [x, innerMap] : mp) {
            vector<int>temp;
            for (auto& [y, mset] : innerMap) {
                for (int val : mset) {
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};