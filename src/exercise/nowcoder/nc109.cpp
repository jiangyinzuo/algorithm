//
// Created by Jiang Yinzuo on 2021/3/15.
//
#include <vector>

using namespace std;

class Solution {
public:
	/**
	 * 判断岛屿数量
	 * @param grid char字符型vector<vector<>>
	 * @return int整型
	 */
	int solve(vector<vector<char> > &grid) {
		// write code here
		int ans = 0;
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j <  grid[0].size(); ++j) {
				if (!visited[i][j] && grid[i][j] == 1) {
					dfs(i, j , visited, grid);
					++ans;
				}
			}
		}
		return ans;
	}

	void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char> > &grid) {
		if (0 <= i && i < visited.size() && 0 <= j && j < visited[0].size() && !visited[i][j] && grid[i][j] == 1) {
			visited[i][j] = true;
			dfs(i-1, j, visited, grid);
			dfs(i+1, j, visited, grid);
			dfs(i, j-1,visited, grid);
			dfs(i,j+1,visited, grid);
		}
	}
};