//
// Created by Jiang Yinzuo on 2021/3/9.
//

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool canCross(vector<int> &stones) {
		std::vector<std::unordered_set<int>> dp(stones.size(), std::unordered_set<int>());
		if (stones[1] != 1) return false;
		dp[1].insert(1);
		int n = stones[stones.size() - 1];
		for(int i = 1; i < stones.size(); i++){
			for(int k : dp[stones[i]]){
				if(stones[i] + k - 1 <= n)
					dp[stones[i] + k - 1].insert(k - 1);
				if(stones[i] + k <= n)
					dp[stones[i] + k].insert(k);
				if(stones[i] + k + 1 <= n)
					dp[stones[i] + k + 1].insert(k + 1);
			}
		}
		return !dp[stones.size() - 1].empty();
	}
};