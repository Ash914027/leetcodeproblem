class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = (int)grid[0].size();
        int N = 2*n-1;
        vector<vector<int>> new_grid;
        new_grid.resize(N);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i >= j) {
                    new_grid[i-j].push_back(grid[i][j]);
                }
                else {
                    new_grid[N-(j-i)].push_back(grid[i][j]);
                }
            }
        }
        for(int i = 0; i <= n-1; i++) {
            sort(new_grid[i].begin(), new_grid[i].end(), greater<int>());
        }
        for(int i = n; i < N; i++) {
            sort(new_grid[i].begin(), new_grid[i].end());
        }
        vector<vector<int>> return_grid;
        return_grid.resize(n);
        for(int i = 0; i < n; i++) {
            return_grid[i].resize(n);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i >= j) {
                    return_grid[i][j] = new_grid[i-j][j];
                }
               else {
                    return_grid[i][j] = new_grid[2*n-1-(j-i)][i];
               }
            }
        }
        return return_grid;
    }
};