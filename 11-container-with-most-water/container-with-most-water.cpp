class Solution {
public:
    int maxArea(vector<int>& height) {
        int widht =0 , lp , rp , h;
        int maxwater = 0;
        int currentwater = 0;
        lp = 0;
        rp = height.size()-1;
        while(lp<rp){
            widht = (rp - lp);
            h = min(height[rp],height[lp]);
            currentwater = widht * h;
            maxwater = max(maxwater,currentwater);
            height[rp]>height[lp]? lp++: rp--;
        }
        return maxwater;
    }
};