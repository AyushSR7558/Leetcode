class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        int n = variables.size();

        for(int i = 0; i < n; i++) {
            int val = 0;
            vector<int> it = variables[i];
            int a = it[0], b = it[1], c = it[2], m = it[3];
            int temp = a % 10;

            for(int i = 1; i < b; i++) {
                temp = (temp * a) % 10;
            }
            int d = temp % m;
            for(int i = 1; i < c; i++) {
                temp = (temp * d) % m;
            }
            if((temp % m) == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};