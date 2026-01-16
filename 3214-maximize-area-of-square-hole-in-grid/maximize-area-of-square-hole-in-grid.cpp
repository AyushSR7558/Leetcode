class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxArea = 0;
        int h = hBars.size(), v = vBars.size();

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxH = 0, maxV = 0, count = 1;

        for(int i = 1; i < h; i++) {
           if(i > 0 && hBars[i] == 1 + hBars[i - 1]) {
                count++;
           }else {
                maxH = max(maxH, count + 1);
                count = 1;
           }
        }
        maxH = max(maxH, count + 1);
        count = 1;

        for(int i = 1; i < v; i++) {
           if(i > 0 && vBars[i] == 1 + vBars[i - 1]) {
                count++;
           }else {
                maxV = max(maxV, count + 1);
                count = 1;
           }
        }
        maxV = max(maxV, count + 1);

        return min(maxV, maxH) * min(maxV, maxH);
    }
};