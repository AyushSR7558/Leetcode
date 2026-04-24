class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size(), dist = 0, curr = 0, cnt = 0;// dist = Store max distance, curr = current position, cnt = total number of _ incountered

        for(int i = 0; i < n; i++) {
            if(moves[i] == 'R') 
                curr++;
            else if(moves[i] == 'L')
                curr--;
            else if(moves[i] == '_')
                cnt++;

        }

        dist = max(abs(curr + cnt), abs(curr - cnt));

        return dist;
    }
};