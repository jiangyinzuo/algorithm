#include <cstdio>
#include <unordered_map>
#include <unordered_set>

std::unordered_map<long long, std::unordered_set<long long> > groups;
std::unordered_map<long long, std::unordered_set<long long> > students;
std::unordered_map<long long, long long> g_s_msg_before;
std::unordered_map<long long, long long> group_msg;

long long msg_cnt[200001] = {0};
long long send_cnt[200001] = {0};
inline long long g_s_id(long long x, long long y) {
    return y * 200005 + x;
}

inline void join_group(long long x, long long y) {
    groups[y].insert(x);
    students[x].insert(y);
    g_s_msg_before[g_s_id(x, y)] = group_msg[y];
}

inline void quit_group(long long x, long long y) {
    groups[y].erase(x);
    students[x].erase(y);
    msg_cnt[x] += group_msg[y] - g_s_msg_before[g_s_id(x, y)];
}

inline void send_msg(long long x, long long y) {
    ++group_msg[y];
    ++send_cnt[x];
}

int main() {
    long long n, m, s;
    scanf("%lld %lld %lld", &n, &m, &s);
    for (long long i = 0; i < s; ++i) {
        long long t, x, y;
        scanf("%lld %lld %lld", &t, &x, &y);
        if (t == 1) {
            join_group(x, y);
        } else if (t == 2) {
            quit_group(x, y);
        } else {
            send_msg(x, y);
        }
    }
    for (int stu = 1; stu <= m; ++stu) {
        for (int g : students[stu]) {
            msg_cnt[stu] += group_msg[g] - g_s_msg_before[g_s_id(stu, g)];
        }
        msg_cnt[stu] -= send_cnt[stu];
        printf("%lld\n", msg_cnt[stu]);
    }
    return 0;
}