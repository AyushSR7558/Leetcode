class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> a, b;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            a[s[i]]++;
        }
        for(int j = 0; j < n; j++) {
            b[t[j]]++;
        }
        return a == b;
    }
};