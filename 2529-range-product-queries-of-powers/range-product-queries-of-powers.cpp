class Solution {
long long modPow(long long base, long long exp, int mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
long long modInverse(long long a, int mod) {
    return modPow(a, mod - 2, mod); // Fermat's Little Theorem
}
vector<int> gavePowerOf2(int n) {
    vector<int> ans;
    int indx = 0;
    while(n) {
        if(n & 1) {
            ans.push_back(1 << indx);
        }
        indx++;
        n = n >> 1;
    }
    return ans;
}
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power = gavePowerOf2(n);
        int np = power.size();
        // Check of the power
        // for(int i = 0; i < power.size(); i++) {
        //     cout << power[i] <<  " ";
        // }
        // cout << endl;
        vector<long long> mulPrefix(np + 1, 1); // To store the multiplication in the prefix format
        vector<int> ans; // To store the final ans
        const int MOD = 1e9 + 7;
        for(int i = 0; i < np ; i++) {
            mulPrefix[i + 1] = ((mulPrefix[i] % MOD) * (power[i] % MOD)) % MOD ;
        }
        for(int i = 0; i < queries.size(); i++) {
            int left = queries[i][0], right = queries[i][1];
            ans.push_back(((mulPrefix[right + 1] % MOD) * (modInverse(mulPrefix[left] , MOD) % MOD)) % MOD);
        }
        return ans;
    }
};