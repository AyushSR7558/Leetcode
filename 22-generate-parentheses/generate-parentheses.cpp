class Solution {
private:
    void generate(vector<string>& a, string& b, int x, int y) {
        if(x == 0 && y == 0) {
            a.push_back(b);
            return;
        }

        if(x - 1 >= 0) {
            b.push_back('(');
            generate(a, b, x - 1, y);
            b.pop_back();
        }

        if(y - 1 >= x) {
            b.push_back(')');
            generate(a, b, x, y - 1);
            b.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> a;
        string temp;
        generate(a, temp, n, n);
        return a;
    }
};