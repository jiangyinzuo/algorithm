#include <cstdio>
#include <cstring>
char text[2000006];

int main() {
    scanf("%s", text);
    int n;
    int len = strlen(text);
    scanf("%d", &n);
    int num;
    char mode[2];
    long long offset = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s %d", &mode, &num);
        if (mode[0] == 'M') {
            offset = (offset + num + len) % len;
        } else if (mode[0] == 'A') {
            printf("%c\n", text[(num - 1 + offset) % len]);
        }
//        for (int j = 1; j <= len; ++j) {
//            printf("%c", text[(j - 1 + offset) % len]);
//        }
//        printf("\n");
    }
    return 0;
}