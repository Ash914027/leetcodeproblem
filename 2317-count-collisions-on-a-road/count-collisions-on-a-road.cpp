class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0;
        int r = n - 1;
        while(l < n  && directions[l] == 'L') l += 1;
        while(r >= 0 && directions[r] == 'R') r -= 1;
        int ans = 0;
        for(int i = l; i <= r; i ++){
            ans += directions[i] != 'S';
        }
        return ans;
    }
};