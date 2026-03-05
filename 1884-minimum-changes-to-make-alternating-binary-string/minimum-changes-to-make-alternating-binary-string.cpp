class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int mini = INT_MAX;
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if((i & 1) && (s[i] != '0')) cnt++;
            if(!(i & 1) && (s[i] != '1')) cnt++;
        }

        mini = cnt;
        cnt = 0;

        for(int i = 0; i < n; i++) {
            if((i & 1) && (s[i] != '1')) cnt++;
            if(!(i & 1) && (s[i] != '0')) cnt++;
        }
        cout << mini << " " <<  cnt;

        return min(cnt, mini);
        
    }
};