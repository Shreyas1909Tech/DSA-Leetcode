class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1) {
            return;
        }
        
       
        grid[r][c] = 0;
        
        
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
       
        for (int row = 0; row < m; row++) {
            if (grid[row][0] == 1) {
                dfs(grid, row, 0);
            }
            if (grid[row][n - 1] == 1) {
                dfs(grid, row, n - 1);
            }
        }
        
        for (int col = 0; col < n; col++) {
            if (grid[0][col] == 1) {
                dfs(grid, 0, col);
            }
            if (grid[m - 1][col] == 1) {
                dfs(grid, m - 1, col);
            }
        }
        
       
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};