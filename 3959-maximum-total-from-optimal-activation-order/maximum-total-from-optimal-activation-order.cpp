class Solution {
private:
    int BinarySearch(vector<pair<int, int>>& mp, int x, int stIndx) {
        int left = stIndx, right = mp.size() - 1, ans = mp.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mp[mid].first <= x) {
                left = mid + 1;
            } else {
                right = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }

public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size(); // Size of value and limit
        vector<pair<int, int>>
            mp; // Will store them corresponding to each other

        for (int i = 0; i < n; i++) {
            mp.push_back(
                {limit[i], value[i]}); // Store all the element in the mp
        }

        sort(mp.begin(), mp.end(), [](auto& a, auto& b) {
            // If the first elements are equal, sort by the second element in
            // descending order.
            if (a.first == b.first) {
                return a.second > b.second;
            }
            // Otherwise, sort by the first element in ascending order.
            return a.first < b.first;
        });

        long long sum = 0, active = 0, stIndx = 0;

        for (int i = 0; i < n; i++) {
            if (i < stIndx)
                continue;
            if (active < mp[i].first) {
                sum += mp[i].second;
                active++;
                int indx = BinarySearch(mp, active, stIndx);
                if (stIndx < indx) {
                    stIndx = indx;
                }
                active = (i - indx + 1 <= 0 ? 0 : i - indx + 1);
            }
        }
        return sum;
    }
};