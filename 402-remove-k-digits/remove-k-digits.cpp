class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size(); // The size of the num 
        list<char> st; // Stack to get the element in the increasing order

        if(k == n) return "0";
        int i = 0;

        while(i < n) {
            while(!st.empty() && st.back() > num[i]) {
                st.pop_back();
                k--;
                if(k == 0) break;
            }
            if(k == 0) break;
            st.push_back(num[i]);
            i++;
        }
        while(k != 0) {
            st.pop_back();
            k--;
        }
        string ans;
        for(char ch : st) {
            ans += ch;
        }
        while(i < n) {
            ans += num[i];
            i++;
        }

        int x = 0;

        while(x < ans.size()) {
            if(ans[x] != '0') {
                break;
            }
            x++;
        }
        string newString = ans.substr(x);
        return (newString == ""? "0": newString);
    }
};