class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int m = dimensions.size();
        double maxiDiagonal = 0;
        int maxiArea = 0;
        for(int i = 0; i < m; i++) {
            int length = dimensions[i][0], widht = dimensions[i][1];
            double diagonal = sqrt(length * length + widht * widht);
            if(diagonal >= maxiDiagonal) {
                if(maxiDiagonal == diagonal){
                    maxiArea = max(length * widht, maxiArea);
                } else {
                    maxiArea = length * widht;
                    maxiDiagonal  = diagonal;
                }
            }
        }
        return maxiArea;
    }
};