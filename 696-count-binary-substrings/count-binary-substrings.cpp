class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int> group;
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(i == 0 || s[i] == s[i - 1]) {
                cnt++;
            } else {
                group.push_back(cnt);
                cnt = 1;
            }
        }
        group.push_back(cnt);
        
        cnt = 0;
        for(int i = 0; i < group.size() - 1; i++) {
            cnt += min(group[i], group[i + 1]);
        }
        return cnt;
        
    }
};