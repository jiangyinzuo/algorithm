//
// Created by Jiang Yinzuo on 2021/3/1.
//

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
#define ADD(idx, limit)  do {\
             while (idx < limit && nums[idx] == nums[idx + 1])\
    ++idx;\
    ++idx;    } while(0);

    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        std::sort(nums.begin(), nums.end());
        for (int first_idx = 0; first_idx <= nums.size() - 4;) {
            for (int second_idx = first_idx + 1; second_idx <= nums.size() - 3; ) {
                int third_idx = second_idx + 1;
                int fourth_idx = ((int)nums.size()) - 1;

                while (third_idx < fourth_idx) {
                    if ((nums[first_idx] + nums[second_idx]) * 2 > target) {
                        break;
                    }
                    int _sum = nums[first_idx] + nums[second_idx] + nums[third_idx] + nums[fourth_idx];
                    if (_sum == target) {
                        res.push_back({nums[first_idx], nums[second_idx], nums[third_idx], nums[fourth_idx]});
                        while (third_idx < fourth_idx && nums[fourth_idx] == nums[fourth_idx - 1])
                            --fourth_idx;
                        fourth_idx--;
                        while (third_idx < fourth_idx && nums[third_idx] == nums[third_idx + 1])
                            ++third_idx;
                        ++third_idx;
                    } else if (_sum > target) {
                        while (third_idx < fourth_idx && nums[fourth_idx] == nums[fourth_idx - 1])
                            --fourth_idx;
                        fourth_idx--;
                    } else {
                        while (third_idx < fourth_idx && nums[third_idx] == nums[third_idx + 1])
                            ++third_idx;
                        ++third_idx;
                    }
                }
                ADD(second_idx, (nums.size() - 3));
            }
            ADD(first_idx, (nums.size() - 4));
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-5,-4,-3,-2,-1,0,0,1,2,3,4,5};
    s.fourSum(nums, 0);
    return 0;
}