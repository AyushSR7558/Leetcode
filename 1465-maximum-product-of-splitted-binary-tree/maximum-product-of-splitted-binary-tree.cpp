class Solution {
    long long maxi = 0;
    int mod = 1e9 + 7;

private:
    long long helper(TreeNode* root, long long totalSum) {
        if (!root) return 0;

        long long left = helper(root->left, totalSum);
        long long right = helper(root->right, totalSum);

        long long subTreeSum = left + right + root->val;

        long long product = subTreeSum * (totalSum - subTreeSum);
        maxi = max(maxi, product);

        return subTreeSum;
    }

public:
    int maxProduct(TreeNode* root) {
        long long totalSum = helper(root, 0); // first pass to get sum
        maxi = 0;
        helper(root, totalSum);               // second pass to compute product
        return maxi % mod;
    }
};
