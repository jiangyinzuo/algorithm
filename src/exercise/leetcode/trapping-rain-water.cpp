//
// Created by Jiang Yinzuo on 2021/3/17.
//
#include <vector>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.empty()) return 0;
		vector<int> left_max(height.size() , 0), right_max(height.size(), 0);

		left_max[0] = height[0];
		for (int i = 1 ; i <height.size(); ++i) {
			left_max[i] = max(left_max[i-1], height[i]);
		}
		right_max[height.size() - 1] = height[height.size() - 1];
		for (int i = height.size() - 2; i >= 0; --i) {
			right_max[i] = max(right_max[i+1], height[i]);
		}
		int ans = 0;
		for (int i = 0; i < height.size(); ++i) {
			ans += (min(left_max[i], right_max[i]) - height[i]);
		}
		return ans;
	}
};