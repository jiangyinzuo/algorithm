//
// Created by Jiang Yinzuo on 2021/3/17 20:51.
//
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>> &matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		vector<vector<int>> up_most(matrix.size(), vector<int>(matrix[0].size()));
		vector<vector<int>> left_most(up_most), right_most(up_most);

		for (int j = 0; j < matrix[0].size(); ++j) {
			up_most[0][j] = matrix[0][j] == '1';
			for (int i = 1; i < matrix.size(); ++i) {
				if (up_most[i][j] == '1') {
					up_most[i][j] = 1 + up_most[i-1][j];
				}
			}
		}

		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix.size(); ++j) {

			}
		}
	}
};