//
// Created by Jiang Yinzuo on 2021/3/18.
//

#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class TreeArr {
	int n;
	vector<int> inner;

	constexpr int lowbit(int x) {
		return x & (-x);
	}

public:
	TreeArr(int _n) : n(_n), inner(_n + 1) {
	}

	void add_val_to_ith(int i, int val) {
		while (i <= n) {
			inner[i] += val;
			i += lowbit(i);
		}
	}

	// [1, i]
	int query_sum_1_to_i(int i) {
		int res = 0;
		while (i > 0) {
			res += inner[i];
			i -= lowbit(i);
		}
		return res;
	}
};

class Solution {
public:
	int reversePairs(vector<int> &nums) {
		std::set<long long> all_nums;
		for (auto i : nums) {
			all_nums.insert(i);
			all_nums.insert(((long long) i) * 2);
		}
		int idx = 0;
		std::unordered_map<long long, int> num_map;
		for (auto i : all_nums) {
			num_map[i] = ++idx;
		}

		TreeArr tree_arr(num_map.size());
		int ans = 0;
		for (int n : nums) {
			int count = tree_arr.query_sum_1_to_i(num_map[(long long) n * 2]);
			int count2 = tree_arr.query_sum_1_to_i(num_map.size());
			ans += (count2 - count);
			tree_arr.add_val_to_ith(num_map[n], 1);
		}
		return ans;
	}
};

int main() {
	Solution s;
	std::vector<int> nums = {1, 2, 1, 2, 1};
	int ans = s.reversePairs(nums);
	printf("%d\n", ans);
	return 0;
}