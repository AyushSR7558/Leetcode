class Solution {
public:
    void generate(vector<string>& mp, string s, int n, int len) {
        if(s.size() == 2 * n) {
            mp.push_back(s);
            return;
        }

        if(len != n) {
            generate(mp, s + '(', n, len + 1);
        }

        if(s.size() < 2 * len) {
            generate(mp, s + ')', n, len);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> mp;
        
        generate(mp, "", n, 0);
        return mp;
        
    }
};