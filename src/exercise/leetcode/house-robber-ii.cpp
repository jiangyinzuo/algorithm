//
// Created by Jiang Yinzuo on 2021/3/18.
//
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		vector<int> n1(nums.begin(), nums.end() - 1), n2(nums.begin() + 1, nums.end());
		return max(solve(n1), solve(n2));
	}

	int solve(vector<int> &nums) {
		vector<int> dp(nums.size(), 0);
		for (int i = 0; i < nums.size(); ++i) {
			dp[i] = max(nums[i] + (i >= 2 ? dp[i-2] : 0), i >= 1 ? dp[i-1] : 0);
		}
		return dp[nums.size() - 1];
	}
};