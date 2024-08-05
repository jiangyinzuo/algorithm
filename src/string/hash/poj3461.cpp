//
// Created by jiang on 2020/8/14.
// POJ3461 子串匹配

#include <cstdio>
#include <cstring>

unsigned char s[1000002];
unsigned char word[10002];

unsigned long hash_table[1000002];
unsigned long p[1000002];

void pre_hash(const unsigned char *str) {
    hash_table[0] = 0;
    p[0] = 1;
    for (int i = 1; str[i - 1]; ++i) {
        hash_table[i] = hash_table[i - 1] * 31 + str[i - 1];
        p[i] = p[i - 1] * 31;
    }
}

/**
 * 获取子串哈希值
 * @param l
 * @param r
 * @return
 */
inline unsigned long get_hash(int l, int r) {
    return hash_table[r] - hash_table[l - 1] * p[r - l + 1];
}

/**
 * BKDR hash函数
 * @param str
 * @return hashcode
 */
unsigned long hashcode(unsigned char *str) {
    unsigned long hash_value = 0;
    for (; *str; ++str) {
        hash_value = hash_value * 31 + *str;
    }
    return hash_value;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        scanf("%s %s", word, s);
        pre_hash(s);

        unsigned long hash_value = hashcode(word);
        int count = 0;
        int n = strlen(reinterpret_cast<const char *>(s));
        int len = strlen(reinterpret_cast<const char *>(word));
        for (int i = 1; i <= n - len + 1; ++i) {
            if (hash_value == get_hash(i, i + len - 1)) {
                ++count;
            }
        }

        printf("%d\n", count);
    }
    return 0;
}