class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> mat2(m, vector<int>(n, 0));

        k %= n;

        for(int i = 0; i < m; i++) {
            k *= -1;
            for(int j = 0; j < n; j++) {
                mat2[i][((j + k) % n < 0? n + ((j + k) % n): ((j + k) % n))] = mat[i][j];
            }
        }
        return mat2 == mat;
    }
};