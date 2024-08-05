//
// Created by Jiang Yinzuo on 2021/3/17.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int maxSizeSlices(vector<int> &slices) {
		vector<int> v1(slices.begin() + 1, slices.end());
		vector<int> v2(slices.begin(), slices.end() - 1);
		return max(calc(v1), calc(v2));

	}

	int calc(vector<int> &slices) {
		int choose = (slices.size() + 1) / 3;
		vector<vector<int>> dp(slices.size(), vector<int>(choose +1, 0));
		dp[0][1] = slices[0];
		dp[1][1] = max(slices[0], slices[1]);
		for (int i = 2; i < slices.size(); ++i) {
			for (int j = 1; j <= min(i+1, choose); ++j) {
				dp[i][j] = std::max(dp[i-1][j], dp[i-2][j-1] + slices[i]);
			}
		}
		return dp[slices.size() - 1][choose];
	}
};

int main() {

	Solution s;
	vector<int> slice = {1, 2, 3, 4, 5, 6};
	std::cout << s.maxSizeSlices(slice);
	return 0;
}