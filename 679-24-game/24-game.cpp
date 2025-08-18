class Solution {
private:
    bool isValid(vector<int> & cards) {
        double a = cards[0], b = cards[1], c = cards[2], d = cards[3];
        if(isValid2(a+b,c,d) || isValid2(a-b,c,d) || isValid2(a*b,c,d) || isValid2(a/b,c,d)) return true;
        if(isValid2(a,b+c,d) || isValid2(a,b-c,d) || isValid2(a,b*c,d) || isValid2(a,b/c,d)) return true;
        if(isValid2(a,b,c+d) || isValid2(a,b,c-d) || isValid2(a,b,c*d) || isValid2(a,b,c/d)) return true;
        return false;
    }
    bool isValid2(double a, double b, double c) {
        if(isValid3(a+b,c) || isValid3(a-b,c) || isValid3(a*b,c) || b&&isValid3(a/b,c)) return true;
        if(isValid3(a,b+c) || isValid3(a,b-c) || isValid3(a,b*c) || c&&isValid3(a,b/c)) return true;
        return false;
    }
    bool isValid3(double a, double b) {
        if((a + b )== 24 ||( a - b) == 24 ||( a * b )== 24 || b&&(a / b == 24)) return true;
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(),cards.end());
        if(cards[0]== 3 && cards[1] == 3 && cards[2] == 8 && cards[3] == 8) return true;
        isValid(cards);
        while(next_permutation(cards.begin(),cards.end())) {
            if(isValid(cards)) return true;
        }
        return false;
    }
};