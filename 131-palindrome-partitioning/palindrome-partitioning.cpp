class Solution {
public:
    bool isPalindromic(string str) {
        string temp = str;
        reverse(str.begin(), str.end());
        return temp == str;
    }
private:
    void helper(vector<vector<string>>& ans, string& s, vector<string>& st, int indx) {
        int n = s.size();
        if(indx == n) {
            ans.push_back(st);
            return ;
        }
        string temp;
        for(int i = indx; i < n; i++) {
            temp.push_back(s[i]);
            if(isPalindromic(temp)) {
                cout << temp << endl;
                st.push_back(temp);
                helper(ans, s, st, i + 1);
                st.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> st;
        helper(ans, s, st, 0);
        return ans;
    }
};