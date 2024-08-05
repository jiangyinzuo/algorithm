//
// Created by Jiang Yinzuo on 2021/3/16.
//
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int findMaxForm(vector<string> &strs, int m, int n) {
		static int dp[101][101] = {0};
//		static bool valid[101][101] = {false};
//		valid[0][0] = true;
		for (auto s : strs) {
			int one_cnt = 0, zero_cnt = 0;
			for (char c : s) {
				if (c == '1') ++one_cnt;
				else if (c == '0') ++zero_cnt;

			}
			for (int i = m; i >= zero_cnt; --i) {
				for (int j = n; j >= one_cnt; --j) {
//					if (valid[i - zero_cnt][j  - one_cnt]) {
						dp[i][j] = std::max(dp[i][j], dp[i - zero_cnt][j - one_cnt] + 1);
//						valid[i][j] = true;
//					}

				}
			}
		}
		return dp[m][n];
	}
};

int main() {
	Solution s;
	vector<string> strs = {"10","0001","111001","1","0"};

	int res = s.findMaxForm(strs, 4, 3);
	cout << res;
	return 0;
}