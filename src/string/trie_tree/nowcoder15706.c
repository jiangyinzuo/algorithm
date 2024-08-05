#include <stdio.h>

int trie_tree[1000005][26] = {0};
long long people_count[1000005] = {0};
long long people_count_prefix[1000005] = {0};
long long people_fame[1000005] = {0};
long long people_fame_prefix[1000005] = {0};
long long update_mark[1000005] = {0};
long long node_count = 0;

// 下推标记至子节点，并删除本节点标记
void push_down(int cur_node)
{
    for (int i = 0; i < 26; ++i) {
        if (trie_tree[cur_node][i]) {
            update_mark[trie_tree[cur_node][i]] += update_mark[cur_node];
            people_fame[trie_tree[cur_node][i]] += people_count[trie_tree[cur_node][i]] * update_mark[cur_node];
            people_fame_prefix[trie_tree[cur_node][i]] += people_count_prefix[trie_tree[cur_node][i]] * update_mark[cur_node];
        }
    }
    update_mark[cur_node] = 0;
}

void insert_node(char *name_prefix, long long fame)
{
    int cur_node = 0;
    for (int i = 0; name_prefix[i]; ++i) {
        // 不存在子节点
        if (trie_tree[cur_node][name_prefix[i] - 'a'] == 0) {
            trie_tree[cur_node][name_prefix[i] - 'a'] = ++node_count;
        }
        cur_node = trie_tree[cur_node][name_prefix[i] - 'a'];
        if (update_mark[cur_node]) {
            push_down(cur_node);
        }
        people_fame_prefix[cur_node] += fame;
        ++people_count_prefix[cur_node];
    }
    people_fame[cur_node] += fame;
    ++people_count[cur_node];
}

void query_fame_by_prefix(char *name_prefix)
{
    int cur_node = 0;
    for (int i = 0; name_prefix[i]; ++i) {
        cur_node = trie_tree[cur_node][name_prefix[i] - 'a'];
        if (cur_node == 0) {
            printf("0\n");
            return;
        }
        if (update_mark[cur_node]) {
            push_down(cur_node);
        }
    }
    printf("%lld\n", people_fame_prefix[cur_node]);
}

void query_fame_by_name(char *name)
{
    int cur_node = 0;
    for (int i = 0; name[i]; ++i) {
        cur_node = trie_tree[cur_node][name[i] - 'a'];
        if (cur_node == 0) {
            printf("0\n");
            return;
        }
        if (update_mark[cur_node]) {
            push_down(cur_node);
        }
    }
    printf("%lld\n", people_fame[cur_node]);
}

//上推，更新祖先节点
void push_up(long long fame, char *name_prefix, int node)
{
    int cur_node = 0;
    for (int i = 0; name_prefix[i]; ++i) {
        cur_node = trie_tree[cur_node][name_prefix[i] - 'a'];
        people_fame_prefix[cur_node] += fame;
    }
}

void update_fame_by_prefix(long long fame, char *name_prefix)
{
    int cur_node = 0;
    for (int i = 0; name_prefix[i]; ++i) {
        cur_node = trie_tree[cur_node][name_prefix[i] - 'a'];
        if (cur_node == 0) {
            return;
        }
        if (update_mark[cur_node]) {
            push_down(cur_node);
        }
    }
    
    long long temp_fame = fame * people_count_prefix[cur_node];
    push_up(temp_fame, name_prefix, cur_node);
    update_mark[cur_node] += fame;
    people_fame[cur_node] += fame * people_count[cur_node];
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int op;
    char name[1000011];
    int fame;
    for (int i = 0; i < n; ++i) {
        scanf("%d %s", &op, name);
        if (op <= 2) {
            scanf("%d", &fame);
        }
        switch (op) {
        case 1:
            insert_node(name, fame);
            break;
        case 2:
            update_fame_by_prefix(fame, name);
            break;
        case 3:
            query_fame_by_name(name);
            break;
        case 4:
            query_fame_by_prefix(name);
            break;
        default:
            break;
        }
    }
    return 0;
}