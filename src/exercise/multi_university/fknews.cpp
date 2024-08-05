//
// Created by Jiang Yinzuo on 2020/8/1.
//

#include <cstdio>
#include <vector>
int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, min, max;

        scanf("%d %d", &n, &m);
        min = n < m ? n : m;
        max = n > m ? n : m;
        int remain = 1;
        while (remain) {
            int total = max - max % min;
            remain = max % min * min;
            if (remain) {
                total += min;
            }
            printf("%d\n", total);
            int count = max - max % min;
            for (int i = 1; i <= count; ++i) {
                if (i == total) printf("%d\n", min);
                else printf("%d ", min);
            }
            if (remain) {
                for (int i = count + 1; i <= total; ++i) {
                    if (i == total) printf("%d\n", remain / min);
                    else printf("%d ", remain / min);
                }
            }
        }


    }
    return 0;
}

