//
// Created by Jiang Yinzuo on 2020/4/11.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *foo(void* args) {

    for (int i = 0; i < 1000000; ++i) {
        printf("hello\n");
        sleep(5);
    }
}

void *bar(void *args) {
    char s[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%s", s);
        printf("echo: %s\n", s);
    }
}

void foo2(void *a) {
    (*(int *)a) = 4;
}

int main() {
//    pthread_t thread1;
//    pthread_t thread2;
//    pthread_create(&thread1, NULL, foo, NULL);
//    pthread_create(&thread2, NULL, bar, NULL);
//    pthread_join(thread1, NULL);
//    pthread_join(thread2, NULL);
    printf("%llu %llu\n", sizeof(char), sizeof(int));

    void *a = malloc(4);
    (*(char *)a) = 'c';
    (*(char*)a)++;
    printf("%c", *(char *)a);
    foo2(a);
    printf("%d", *(char *)a);
    return 0;
}