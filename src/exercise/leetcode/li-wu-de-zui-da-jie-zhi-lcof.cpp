//
// Created by Jiang Yinzuo on 2021/3/16.
//
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		vector<vector<int>> dp(grid.size(), vector<int>(grid.size(), 0));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < grid.size(); ++i) {
			dp[i][0] += dp[i-1][0];
		}
		for (int j = 1; j < grid[0].size(); ++j) {
			dp[0][j] += dp[0][j-1];
		}
		for (int i = 1; i < grid.size(); ++i) {
			for (int j = 1; j < grid[0].size(); ++j) {
				dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
			}
		}
		return dp[grid.size()][grid[0].size()];
	}
};