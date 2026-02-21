class Solution {
private:
    unordered_set<int> sieveOfEratosthenes() {
        vector<bool> prime(32, true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 2; i * i < 32; i++) {
            if(prime[i]) {
                for(int j = i * i; j < 32; j += i) {
                    prime[j] = false;
                }
            } 
        }
        unordered_set<int> st;
        for(int i = 0; i < 32; i++) 
            if(prime[i]){
                st.insert(i);
            };
        return st;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        unordered_set<int> st = sieveOfEratosthenes();

        for(int i = left; i <= right; i++) {
            if(st.count(__builtin_popcount(i))) {
                count++;
            }
        }
        return count;
    }
};