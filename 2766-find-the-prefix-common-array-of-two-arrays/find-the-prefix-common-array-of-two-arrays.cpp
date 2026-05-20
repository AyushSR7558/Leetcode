class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> a(n + 1, false), b(n + 1, false);
        vector<int> pre;
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            a[A[i]] = true;
            b[B[i]] = true;

            if(A[i] == B[i]) {
                cnt++;
                pre.push_back(cnt);
                continue;
            }
            if(a[A[i]] && b[A[i]])
                cnt++;

            if(a[B[i]] && b[B[i]]) 
                cnt++;
            

            pre.push_back(cnt);
        }
        return pre;
    }
};