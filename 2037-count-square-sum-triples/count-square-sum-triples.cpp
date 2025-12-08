class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        unordered_set<int> mp;
        for(int i = 1; i <= n; i++) {
            mp.insert(i * i);
        }

        for(int c = 1; c <= n; c++) {
            for(int b = 1; b < c; b++) {
                if(mp.count(c * c - b * b)) count++;
            }
        }
        return count;
    }
};