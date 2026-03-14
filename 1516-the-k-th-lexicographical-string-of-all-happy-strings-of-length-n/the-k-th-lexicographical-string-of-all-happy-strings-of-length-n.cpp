class Solution {
private:
    void helper(vector<string>& ps, string& temp, int n) {
        if(n == 0) {
            ps.push_back(temp);
            return ;
        }

        for(int i = 0; i < 3; i++) {
            if(!temp.empty() && temp.back() == (i + 'a')) continue;
            temp.push_back((char)('a' + i));
            helper(ps, temp, n - 1);
            temp.pop_back();
        }
    }

public:
    string getHappyString(int n, int k) {
        vector<string> ps;
        string temp;
        helper(ps, temp, n);
        if(k > ps.size()) return "";
        return ps[k - 1];
    }
};