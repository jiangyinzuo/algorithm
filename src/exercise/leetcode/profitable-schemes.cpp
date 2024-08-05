//
// Created by Jiang Yinzuo on 2021/3/9.
//
#include <vector>

using namespace std;

class Solution {
public:
	int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
		vector<vector<long long>> dp(minProfit + 1, vector<long long>(n + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i < group.size(); ++i) {
			for (int j = n; j >= group[i]; --j) {
				for (int k = minProfit + profit[i]; k >= profit[i]; --k) {
					dp[std::min(k, minProfit)][j] += dp[k - profit[i]][j - group[i]] % 1000000007;
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i <= n; ++i) {
			ans = (ans + dp[minProfit][i]) % 1000000007;
		}
		return (int) ans;
	}
};

class Solution2 {
public:
	int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
		vector<vector<long long>> dp(minProfit + 1, vector<long long>(n + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i < group.size(); ++i) {
			for (int k = minProfit + profit[i]; k >= profit[i]; --k) {
				for (int j = n; j >= group[i]; --j) {
					dp[std::min(k, minProfit)][j] += dp[k - profit[i]][j - group[i]] % 1000000007;
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i <= n; ++i) {
			ans = (ans + dp[minProfit][i]) % 1000000007;
		}
		return (int) ans;
	}
};
