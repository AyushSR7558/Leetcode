class Solution {
public:
    void helper(vector<string>& v, string a, int op, int cl, int n) {
        if (op + cl >= n) {
            v.push_back(a);
            return;
        }
        if (cl<op) {
            helper(v, a + ')', op, cl + 1, n );
        }
        if(2*op < n){
            helper(v, a + '(', op + 1, cl, n);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        int a = 2*n;
        vector<string> v;
        helper(v,"",0,0,a);
        return v;

    }
};