class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();    
        vector<int> seats;

        for(int i = 0; i < n; i++) 
            if(corridor[i] == 'S') seats.push_back(i);

        int m = seats.size();

        if(m == 0 || m % 2) return 0;

        int mod = 1e9 + 7;
        long long ways = 1;

        for(int i = 2; i < m; i+= 2) {

            int gap = seats[i] - seats[i - 1];
            ways = (ways * gap) % mod;

        }

        return ways;
        
    }
};