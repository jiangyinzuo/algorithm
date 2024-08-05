//
// Created by Jiang Yinzuo on 2021/3/2.
//

#include <cstdio>
#include <stack>
#include <algorithm>

int mat[1008][1008] = {0};
int up[1008][1008] = {0};

int n, m;
struct Node {
    int fold_width;
    int height;
};

void solve(int row, int &max_ans) {

    std::stack<Node> mono_stack;
    mono_stack.push({1, up[row][1]});
    for (int i = 2 ; i <= m; ++i) {
        int fold_width = 1;
        while (!mono_stack.empty() && up[row][i] < mono_stack.top().height) {
            fold_width += mono_stack.top().fold_width;
            mono_stack.pop();
            max_ans = std::max(max_ans, fold_width * mono_stack.top().height);
        }
        mono_stack.push({fold_width, up[row][i]});
    }
    int fold_width = 1;
    while (!mono_stack.empty() ) {
        fold_width += mono_stack.top().fold_width;
        mono_stack.pop();
        max_ans = std::max(max_ans, fold_width * mono_stack.top().height);
    }

}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            char c;
            scanf("%c", &c);
            if (c == 'F')
                mat[i][j] = 1;

            up[i][j] = up[i][j - 1] + 1;
        }
    }

    int max_ans = 0;
    for (int row = 1; row <= n; ++row) {
        solve(row, max_ans);
    }
    printf("%d\n", max_ans * 3);
    return 0;
}