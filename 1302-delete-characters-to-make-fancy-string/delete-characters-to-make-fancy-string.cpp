class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size(), indx = 1;
        int freq = 1;
        string temp;
        temp.push_back(s[0]);
        while(indx < n){
            if(s[indx] == s[indx - 1]){
                freq++;
                if(freq <= 2){
                    temp.push_back(s[indx]);
                }
            }else{
                freq = 1;
                temp.push_back(s[indx]);
            }
            indx++;
        }
        return temp;
    }
};