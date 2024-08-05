#include <stdio.h>

int main()
{
    int n, money;
    scanf("%d %d", &n, &money);

    int value[100];
    int method_count[10009] = {0};
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = money - value[i]; j > 0; --j) {
            if (method_count[j]) {
                method_count[j + value[i]] += method_count[j];
            }
        }
        method_count[value[i]]++;

        for (int k = 0; k <= money; ++k) {
            printf("%d ", method_count[k]);
        }
        printf("\n");
        
    }
    printf("%d\n", method_count[money]);
    return 0;
}