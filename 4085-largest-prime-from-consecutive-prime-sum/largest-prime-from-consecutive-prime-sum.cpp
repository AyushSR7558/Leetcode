class Solution {
private:
    vector<int> sieveOfEratosthenes (int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = false;
        prime[1] = false;
        for(int p = 2; p * p <= n; p++) {
            if(prime[p]) {
                for(int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            if(prime[i]) ans.push_back(i);
        }
        return ans;
    }
public:
    int largestPrime(int n) {
        vector<int> prime = sieveOfEratosthenes(n);
        unordered_set<int> mp(prime.begin(), prime.end());
        int sum = 0, prev = 0;
        for(int i = 0; i < prime.size() && sum <= n; i++) {
            sum += prime[i];
            if(mp.count(sum)) prev = sum;
        }
        if(sum <= n) {
            if(mp.count(sum)) prev = sum;
        }

        return prev;
    }
};