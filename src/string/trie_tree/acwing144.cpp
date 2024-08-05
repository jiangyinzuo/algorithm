//
// Created by Jiang Yinzuo on 2020/12/10.
//
#include <cstdio>

template<const int NumCh, const char BaseCh, const int TextTotLen>
struct Trie {
protected:
    int next[TextTotLen][NumCh], idx;
    bool exist[TextTotLen];  // 该结点结尾的字符串是否存在

public:
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
protected:
    int visited_cnt[TextTotLen]{0};
    int existed_cnt[TextTotLen]{0};
public:
    /**
     * 插入字符串
     * @param s 待插入的字符串
     */
    void insert(char *s) {
        int p = 0;
        for (int i = 0; s[i]; ++i) {
            int c = s[i] - BaseCh;
            if (!this->next[p][c])
                this->next[p][c] = ++this->idx;  // 如果没有，就添加结点
            p = this->next[p][c];
        }
        ++existed_cnt[p];
    }

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

    int prefix_cnt(char *s) {
        int res = 0, p = 0;
        for (int i = 0; s[i]; ++i) {
            int c = s[i] - BaseCh;
            if (!this->next[p][c])
                return res;
            p = this->next[p][c];
            res += this->existed_cnt[p];
        }
        return res;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    static char s[1000001];
    static FindPrefixTrie<26, 'a', 1000001> trie;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        trie.insert(s);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s", s);
        printf("%d\n", trie.prefix_cnt(s));
    }
    return 0;
}