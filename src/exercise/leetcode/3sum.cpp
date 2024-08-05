#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n ; i++) {
            if (nums[i] > 0)
                return res;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r]== 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1])
                        ++l;
                    while (l < r && nums[r] == nums[r + 1])
                        --r;
                    ++l;
                    --r;
                } else if (nums[i] + nums[l] + nums[r]> 0) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {};
    auto res = s.threeSum(nums);
    for (auto v : res) {
        for (auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}