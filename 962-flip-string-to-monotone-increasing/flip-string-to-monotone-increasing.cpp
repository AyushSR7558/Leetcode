class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> rP(n,0);
        if(s[n - 1] == '0') rP[n - 1] ++;
        for(int i = n - 2; i >= 0; i--) {
            rP[i] = rP[i + 1];
            if(s[i] == '0') {
                rP[i]++;
            }
        }
        int countOne = 0;
        int miniChange = INT_MAX;
        for(int i = 0; i < n; i++) {
            int count = rP[i] + countOne;
            if(s[i] == '0') count--;
            miniChange = min(miniChange,count);
            if(s[i] == '1') countOne++;
        }
        return miniChange;
    }
};