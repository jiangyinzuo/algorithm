//
// Created by Jiang Yinzuo on 2021/3/17.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	enum P {
		ABA, ABC,
		ACA, ACB,
		BAB, BAC,
		BCB, BCA,
		CAC, CAB,
		CBC, CBA,
	};

	int numOfWays(int n) {
		if (n == 1) return 12;
		if (n == 0) return 0;
		vector<vector<int>> dp(n + 1, vector<int>(12, 1));
		for (int i = 2; i <= n; ++i) {
			// ABA
			dp[i][ABA] = add(add(add(add(dp[i - 1][BAB], dp[i - 1][BAC]), dp[i - 1][BCB]), dp[i - 1][CAC]), dp[i - 1][CAB]);
			dp[i][CBC] = dp[i][BCB] = dp[i][CAC] = dp[i][BAB] = dp[i][ACA] = dp[i][ABA];
			// ABC
			dp[i][ABC] = add(add(add(dp[i - 1][BAB] ,dp[i - 1][BCB]) , dp[i - 1][BCA]) , dp[i - 1][CAB]);
			dp[i][ACB] = dp[i][BAC] = dp[i][BCA] = dp[i][CAB] = dp[i][CBA] = dp[i][ABC];
		}
		int sum = 0;
		for (int i : dp[n]) {
			// cout << i << " ";
			sum = add(sum, i);
		}
		return sum;
	}

	int add(int a, int b) {
		return (a+b) % 1000000007;
	}
};

int main() {
	Solution s;
	cout << s.numOfWays(2);
	return 0;
}