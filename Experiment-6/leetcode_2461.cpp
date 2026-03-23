#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long MOD = 1e9 + 7;
        vector<vector<long long>> dpMax(m, vector<long long>(n)), dpMin(m, vector<long long>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dpMax[i][j] = dpMin[i][j] = grid[i][j];
                } else if (i == 0) {
                    dpMax[i][j] = dpMin[i][j] = dpMax[i][j - 1] * grid[i][j];
                } else if (j == 0) {
                    dpMax[i][j] = dpMin[i][j] = dpMax[i - 1][j] * grid[i][j];
                } else if (grid[i][j] == 0) {
                    dpMax[i][j] = dpMin[i][j] = 0;
                } else {
                    long long a = dpMax[i - 1][j] * grid[i][j], b = dpMin[i - 1][j] * grid[i][j];
                    long long c = dpMax[i][j - 1] * grid[i][j], d = dpMin[i][j - 1] * grid[i][j];
                    dpMax[i][j] = max({a, b, c, d});
                    dpMin[i][j] = min({a, b, c, d});
                }
            }
        }
        return (dpMax[m - 1][n - 1] < 0) ? -1 : dpMax[m - 1][n - 1] % MOD;
    }
};
