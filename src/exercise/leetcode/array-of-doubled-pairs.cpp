//
// Created by Jiang Yinzuo on 2021/3/2.
//
#include <algorithm>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        std::set<int> s;
        std::unordered_map<int, int> m;
        for (auto i : arr) {
            s.insert(i);
            m[i]++;
        }
        for (auto key : s) {
            if (key == 0) {
                if (m[key] % 2 != 0)
                    return false;
            } else if (key < 0) {
                if (key % 2 == 0 && m[key] <= m[key / 2]) {
                    m[key / 2] -= m[key];
                    m[key] = 0;
                } else if (m[key]){
                    return false;
                }
            } else {
                if (m[key] <= m[key * 2]) {
                    m[key * 2] -= m[key];
                    m[key] = 0;
                } else if (m[key]) {
                    return false;
                }
            }
        }
        return true;
    }

};

int main() {
    Solution s;
    vector<int> a = {-2, -6, -3, 4, -4, 2};
    bool ans = s.canReorderDoubled(a);
    printf("%d", ans);
    return 0;
}