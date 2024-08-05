#include <iostream>

using namespace std;

int trie[1000010][26];
int total[1000010] = {0};
int node = 1;

void insert(char *words)
{
    int parent = 1;
    for (int i = 0; words[i]; ++i) {
        if (trie[parent][words[i] - 'a'] == 0) {
            trie[parent][words[i] - 'a'] = ++node;
        }
        parent = trie[parent][words[i] - 'a'];
        ++total[parent];
    }
}

int query(char *prefix)
{
    int parent = 1;
    for (int i = 0; prefix[i]; ++i) {
        if (trie[parent][prefix[i] - 'a'] == 0) {
            return 0;
        }
        parent = trie[parent][prefix[i] - 'a'];
    }
    return total[parent];
}

int main()
{
    char words[15] = {'\0'};
    
    while (cin.getline(words, 14)) {
        if (words[0] == '\0') {
            break;
        }
        insert(words);
    }

    while (cin >> words) {
        cout << query(words) << endl;
    }

    return 0;
}