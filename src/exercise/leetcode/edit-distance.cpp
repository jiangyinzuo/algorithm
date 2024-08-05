//
// Created by Jiang Yinzuo on 2021/3/18.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

		for (int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
		for (int j = 0; j <= word2.size(); ++j) dp[0][j] = j;
		int i = 1;
		for (char w1 : word1) {
			int j = 1;
			for (char w2 : word2) {
				if (w1 == w2)
					dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j] + 1), dp[i][j - 1] + 1);
				else {
					dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
				}
				++j;
			}
			++i;
		}
		return dp[word1.size()][word2.size()];
	}
};