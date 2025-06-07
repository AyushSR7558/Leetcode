class Solution {
public:
    string add(string a, string b) {
        int count = 0, carry = 0;
        int i1 = a.length() - 1, i2 = b.length() - 1;
        string ans = "";
        while (i1 >= 0 && i2 >= 0) {
            int x = a[i1] - '0', y = b[i2] - '0';
            int count = x + y + carry;
            if (count == 3) {
                ans = '1' + ans;
                carry = 1;
            } else if (count == 2) {
                ans = '0' + ans;
                carry = 1;
            } else if (count == 1) {
                ans = '1' + ans;
                carry = 0;
            } else {
                ans = '0' + ans;
                carry = 0;
            }
            i1--;
            i2--;
        }
        while (i1 >= 0) {
            int x = a[i1] - '0';
            count = x + carry;
            if (count == 2) {
                ans = '0' + ans;
                carry = 1;
            } else if (count == 1) {
                ans = '1' + ans;
                carry = 0;
            } else {
                ans = '0' + ans;
                carry = 0;
            }
            i1--;
        }
        if(carry) ans = '1'+ans;
        return ans;
    }
    string addBinary(string a, string b) {
        int i1 = a.length() - 1, i2 = b.length() - 1;
        string ans = "";
        if (i1 > i2) {
            ans = add(a, b);
        } else
            ans = add(b, a);
        return ans;
    }
};