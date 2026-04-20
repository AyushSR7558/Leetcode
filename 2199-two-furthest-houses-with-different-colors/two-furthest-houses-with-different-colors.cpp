class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int dist = 0, n = colors.size();

        int i = 0, j = n - 1;
        while(j > 0 && colors[i] == colors[j]) {
            j--;
        }
        dist = max(j - i, dist);
        
        i = n - 1;
        j = 0;
        while(j < n - 1 && colors[i] == colors[j]) {
            j++;
        }
        dist = max(i - j, dist);
        return dist;

    }
};