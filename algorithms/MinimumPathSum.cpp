// Problem Source : https://leetcode.com/problems/minimum-path-sum/
// Solution Source : https://github.com/soulmachine/leetcode
// Date : 2016/10/10

// Given a m x n grid filled with non-negative numbers, find a path from top left
// to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.

// 设状态为 f[i][j]，表示从起点 (0, 0) 到达 (i, j)的最小路径和，则状态转移方程为：
// f[i][j]=min(f[i-1][j], f[i][j-1])+grid[i][j]

//备忘录法
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        cache = vector<vector<int>>(m, vector<int>(n, -1));
        return dfs(grid, m-1, n-1);
    }
private:
    vector<vector<int>> cache; // 缓存
    int dfs(const vector<vector<int>>& grid, int x, int y)
    {
        if(x==0 && y==0) return grid[0][0]; // 收敛条件
        return min(getOrUpdate(grid, x-1, y), getOrUpdate(grid, x, y-1)) + grid[x][y];
    }
    int getOrUpdate(const vector<vector<int>>& grid, int x, int y)
    {
        if(x<0 || y<0) return INT_MAX; // 越界，注意是 <
        if(cache[x][y] >= 0) return cache[x][y];
        return cache[x][y] = dfs(grid, x, y);
    }
};

// 动态规划
class Solution {
public:
  int minPathSum(vector<vector<int> > &grid) {
    if (grid.size() == 0) return 0;
    const int m = grid.size();
    const int n = grid[0].size();
    
    int f[m][n];
    f[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) {
      f[i][0] = f[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; i++) {
      f[0][i] = f[0][i - 1] + grid[0][i];
    }
    
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
      }
    }
    return f[m - 1][n - 1];
  }
};

// 动规+滚动数组
class Solution {
public:
  int minPathSum(vector<vector<int> > &grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    
    int f[n];
    fill(f, f+n, INT_MAX); // 初始值是 INT_MAX，因为后面用了 min 函数
    f[0] = 0;

    for (int i = 0; i < m; i++) {
      f[0] += grid[i][0];
      for (int j = 1; j < n; j++) {
        // 左边的 f[j]，表示更新后的 f[j]，与公式中的 f[i][j] 对应
        // 右边的 f[j]，表示老的 f[j]，与公式中的 f[i-1][j] 对应
        f[j] = min(f[j - 1], f[j]) + grid[i][j];
      }
    }
    return f[n - 1];
  }
};
