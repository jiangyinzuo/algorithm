//
// Created by Jiang Yinzuo on 2021/6/12.
//
#include <iostream>

class Trie {
    int node[1000008][26]{0};
    int key_count[1000008]{0};
    int next_node_idx = 1;

public:
    void AddKey(std::string const &key) {
        int cur_idx = 0;
        for (char c : key) {
            if (node[cur_idx][c - 'a'] == 0) {
                node[cur_idx][c - 'a'] = next_node_idx++;
            }
            cur_idx = node[cur_idx][c - 'a'];
        }
        ++key_count[cur_idx];
    }

    int FindPrefixCount(std::string const &key) const {
        int cur_idx = 0;
        int ans = 0;
        ans += key_count[cur_idx];
        for (char c : key) {
            cur_idx = node[cur_idx][c - 'a'];
            if (cur_idx == 0) {
                break;
            }
            ans += key_count[cur_idx];
        }
        return ans;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    Trie *trie = new Trie();
    std::string key;
    for (int i = 0; i < n; ++i) {
        std::cin >> key;
        trie->AddKey(key);
    }
    for (int i = 0; i  < m; ++i) {
        std::cin >> key;
        int ans = trie->FindPrefixCount(key);
        std::cout << ans << '\n';
    }
    delete trie;
    return 0;
}