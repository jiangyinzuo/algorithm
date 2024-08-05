//
// Created by Jiang Yinzuo on 2020/12/10.
//
#include <cstdio>

template<const int NumCh, const char BaseCh, const int TextTotLen>
struct Trie {
    int next[TextTotLen][NumCh], idx;
    bool exist[TextTotLen];  // 该结点结尾的字符串是否存在

    /**
     * 插入字符串
     * @param s 待插入的字符串
     */
    void insert(char *s) {
        int p = 0;
        for (int i = 0; s[i]; ++i) {
            int c = s[i] - BaseCh;
            if (!next[p][c])
                next[p][c] = ++idx;  // 如果没有，就添加结点
            p = next[p][c];
        }
        exist[p] = true;
    }

    /**
     * 查找字符串
     * @param s 待查找的字符串
     * @return 是否存在
     */
    bool find(char *s) {
        int p = 0;
        for (int i = 0; s[i]; ++i) {
            int c = s[i] - BaseCh;
            if (!next[p][c])
                return false;
            p = next[p][c];
        }
        return exist[p];
    }
};

template<const int NumCh, const char BaseCh, const int TextTotLen>
struct FindPrefixTrie : public Trie<NumCh, BaseCh, TextTotLen> {
    int visited_cnt[TextTotLen]{0};

    /**
     * 插入时检查s和Trie中的字符串是否存在前缀关系
     * @return True: 没有前缀；false:s是Trie中的字符串的前缀，或Trie中的字符串是s的前缀
     */
    bool insert_no_prefix(char *s) {
        int p = 0;
        for (int i = 0; s[i]; ++i) {
            int c = s[i] - BaseCh;
            if (!this->next[p][c])
                this->next[p][c] = ++this->idx;
            p = this->next[p][c];
            if (this->exist[p]) {
                return false;  // Trie中某个字符串是s的前缀
            }
            ++visited_cnt[p];
        }
        this->exist[p] = true;
        return this->visited_cnt[p] <= 1;  // 若为false，代表s是Trie中某字符串的前缀
    }

    /**
     * 查找Trie中是否存在字符串s的前缀
     * @param s 待查找的字符串
     * @return 是否存在
     */
    bool find_prefix(char *s) {
        int p = 0;
        for (int i = 0; s[i]; ++i) {
            int c = s[i] - BaseCh;
            if (!this->next[p][c])
                return false;
            p = this->next[p][c];
            if (this->exist[p])
                return true;
        }
        return this->exist[p];
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        int n;
        scanf("%d", &n);
        static char text[10001];
        auto *trie = new FindPrefixTrie<10, '0', 100000>();
        bool has_no_prefix = true;
        for (int i = 0; i < n; ++i) {
            scanf("%s", text);
            if (!has_no_prefix || !trie->insert_no_prefix(text)) {
                has_no_prefix = false;
            }
        }
        printf("Case #%d: %s\n", kase, has_no_prefix ? "Yes" : "No");
        delete trie;
    }
    return 0;
}