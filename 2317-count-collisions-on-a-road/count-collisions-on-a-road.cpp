class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        vector<int> leftToRight(n), rightToLeft(n);

        int ctn = 0;
        for(int i = 0; i < n; i++) {
            if(directions[i] == 'R') {
                leftToRight[i] = ++ctn;
            }else {
                leftToRight[i] = ctn;
                ctn = 0;
            }
        }

        ctn = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(directions[i] == 'L') {
                rightToLeft[i] = ++ctn;
            }else {
                rightToLeft[i] = ctn;
                ctn = 0;
            }
        }

        int collCnt = 0;
        for(int i = 0; i < n; i++) {
            if(directions[i] == 'S') {
                collCnt += leftToRight[i] + rightToLeft[i];
            }
            if(directions[i] == 'R') {
                collCnt += (rightToLeft[i] > 0? leftToRight[i] + rightToLeft[i]: 0);
            }
        }
        return collCnt;
    }
};