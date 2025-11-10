class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ops = 0;
        stack<int> st;
        st.push(0);  // sentinel

        for (int x : nums) {
            while (st.top() > x) {
                st.pop();
                ops++;
            }
            if (st.top() < x) {
                st.push(x);
            }
        }
    // finish off any remaining positive strokes
        while (st.top() > 0) {
            st.pop();
            ops++;
        }
        return ops;
    }
};