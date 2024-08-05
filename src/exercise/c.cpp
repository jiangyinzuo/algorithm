//
// Created by Jiang Yinzuo on 2020/5/5.
//

#include <cstdio>
#include <algorithm>
#include <set>
#include <forward_list>
struct Homework {
    int ddl;
    int value;

    bool operator<(const Homework &h) const {
        return value > h.value || value == h.value && ddl < h.ddl;
    }
} homework[1009];

std::set<int> quest;

int main() {
    int t;
    scanf("%d", &t);

    int n;
    int latest_day;
    while (t--) {
        quest.clear();
        latest_day = 0;
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &homework[i].ddl);
            latest_day = latest_day > homework[i].ddl ? latest_day : homework[i].ddl;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &homework[i].value);
            sum += homework[i].value;
        }
        std::sort(homework, homework + n);

        int done_count = 0;

        int total_done = 0;
        int idx = 0;
        while (done_count < latest_day && done_count < n && idx < n) {
            int ddl = homework[idx].ddl;
            while (quest.find(ddl) != quest.end()) {
                ddl--;
            }
            if (ddl > 0) {
                quest.insert(ddl);
                done_count++;
                total_done += homework[idx].value;
            }
            idx++;
        }
        printf("%d\n", sum - total_done);
    }
    return 0;
}