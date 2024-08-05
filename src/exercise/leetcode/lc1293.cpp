//
// Created by Jiang Yinzuo on 2021/4/21.
//
#include <vector>

using namespace std;

class Solution {
public:
	int shortestPath(vector<vector<int>> &grid, int k) {
		vector<vector<vector<int>>> dp(grid.size(), vector<int>(grid[0].size(), vector<int>(k, 0)));
	}
};