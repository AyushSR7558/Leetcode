class Solution {
    unordered_set<char> opt = {'+', '-', '*', '/'};
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();

        vector<int> res;

        for(int i = 0; i < n; i++) {
            if(opt.count(expression[i])) {
                string s1 = expression.substr(0, i);
                string s2 = expression.substr(i + 1);

                vector<int> a = diffWaysToCompute(s1);
                vector<int> b = diffWaysToCompute(s2);

                for(int p : a) {
                    for(int q : b) {
                        if(expression[i] == '*') res.push_back(p * q);
                        else if(expression[i] == '+') res.push_back(p + q);
                        else if(expression[i] == '-') res.push_back(p - q);
                        else if(expression[i] == '/') res.push_back(p / q); 
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(expression));
        return res;
    }
};