class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long>time(skill.size() + 1);
        int n = skill.size();
        int m = mana.size();
        for(int i = 0; i < m; i++){
            for(int j = 1; j <= n; j++){
                time[j] = max(time[j - 1], time[j]) + skill[j-1] * mana[i];
            }
            for(int j = n - 1; j >= 0; j--){
                time[j] = time[j + 1] - skill[j] * mana[i];
            }
        }
        return time[n];
    }
};