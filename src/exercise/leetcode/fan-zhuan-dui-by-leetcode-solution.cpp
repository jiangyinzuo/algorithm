//
// Created by Jiang Yinzuo on 2021/3/17.
//

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) return false;
		vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1));
		dp[0][0] = true;

		for (int i = 0; i <= s1.size(); ++i) {
			for (int j = 0; j <= s2.size(); ++j) {
				if (i)
					dp[i][j] = dp[i][j] | (dp[i-1][j] & (s1[i-1] == s3[i+j-1]));
				if (j)
					dp[i][j] = dp[i][j] | dp[i][j-1] & (s2[j-1] == s3[i+j-1]);
			}
		}
		return dp[s1.size()][s2.size()];
	}
};