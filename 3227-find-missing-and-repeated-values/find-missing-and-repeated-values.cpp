class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> mp(n * n + 1,0);
        int a, b;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                mp[grid[i][j]]++;
                if(mp[grid[i][j]]== 2) a = grid[i][j];
            }
        } 
        for(int i = 1; i < n * n; i++){
            if(mp[i] == 0) {
                b = i;
                break;
            }
        }
        return {a, b};
    }
};