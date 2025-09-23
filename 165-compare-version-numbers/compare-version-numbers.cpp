class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(!version1.empty() || !version2.empty()) {
            int temp1 = 0, temp2 = 0;
            if(!version1.empty()){
                string newVersion = version1.substr(0,version1.find('.'));
                temp1 = stoi(newVersion);
                if(newVersion == version1){
                    version1 = "";
                }else{
                    version1 = version1.substr(version1.find('.') + 1);
                }
            }
            if(!version2.empty()){
                string newVersion = version2.substr(0,version2.find('.'));
                temp2 = stoi(newVersion);
                if(newVersion == version2){
                    version2 = "";
                }else {
                    version2 = version2.substr(version2.find('.') + 1);
                }
            }
            cout << "temp1 = " << temp1 << " " << "temp2 = " << temp2;
            if(temp1 < temp2) return -1;
            if(temp1 > temp2) return 1;
        }
        return 0;
    }
};