class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> nums;
        map<int,vector<int>> mp;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        for(int i = 0; i <= m + n - 2; i++) {
            vector<int> init = mp[i];
            if(!(i & 1)) {
                reverse(init.begin(),init.end());
            }
            for(int i = 0; i < init.size(); i++) {
                nums.push_back(init[i]);
            }
        }
        return nums;
    }
};