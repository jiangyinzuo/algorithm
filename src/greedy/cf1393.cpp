//
// Created by Jiang Yinzuo on 2020/8/11.
//

#include <cstdio>
#include <unordered_map>
#include <map>

void solve(std::map<int, int, std::greater<> > &nums_count) {
    int distance = 0;
    int remain = 0;
    const int group = nums_count.begin()->first;
    for (auto i : nums_count) {
        if (i.first == group)
            distance += i.second - 1;
        else {
            distance += std::max(0, std::max(i.first * i.second - remain, 0) / (group - 1));
            remain = (group - 1 - remain + i.first * i.second) % (group - 1);
        }
    }

    printf("%d\n", distance);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        std::unordered_map<int, int> nums;
        std::map<int, int, std::greater<> > nums_count;
        int a;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            ++nums[a];
        }
        for (auto &i : nums) {
            ++nums_count[i.second];
        }
        solve(nums_count);
    }
    return 0;
}