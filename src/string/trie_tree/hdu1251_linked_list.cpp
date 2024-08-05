#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    int total;
    Node *next[26];
    Node() {
        for (int i=0; i<26; ++i) {
            this->next[i] = NULL;
        }
        this->total = 0;
    }
    void insert(char *word, int length) {
        ++this->total;

        Node *parent = this;
        for (int i = 0; i < length; ++i) {
            if (parent->next[word[i] - 'a'] == NULL) {
                parent->next[word[i] - 'a'] = new Node();
            }
            parent = parent->next[word[i] - 'a'];
            ++parent->total;
        }
    }
    int query(char *prefix, int length) {
        Node *parent = this;
        for (int i = 0; i < length; ++i) {
            if (parent->next[prefix[i] - 'a'] == NULL) {
                return 0;
            }
            parent = parent->next[prefix[i] - 'a'];
        }
        return parent->total;
    }
    ~Node() {
        for (int i = 0; i < 26; ++i) {
            if (this->next[i] != NULL) {
                delete this->next[i];
            }
        }
        delete this;
    }
};

int main()
{
    char words[15];
    Node *root = new Node();
    while (cin.getline(words, 14)) {
        if (words[0] == '\0') {
            break;
        }
        root->insert(words, strlen(words));
    }

    while (cin >> words) {
        cout << root->query(words, strlen(words)) << endl;
    }

    root->~Node();
    return 0;
}