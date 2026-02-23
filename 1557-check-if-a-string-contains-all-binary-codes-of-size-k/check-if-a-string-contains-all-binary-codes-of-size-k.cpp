class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string> cnt;
        string temp;

        for(int i = 0; i < n; i++) {
            if(temp.size() >= k) {
                temp.erase(0,1);
            }
            temp.push_back(s[i]);
            if(temp.size() == k) {
                cnt.insert(temp);
            }
        }

        return cnt.size() == (1 << k);
    }
};