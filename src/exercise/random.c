//
// Created by Jiang Yinzuo on 2020/4/29.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(0));


    int lose = 0;
    for (int j = 0; j < 1000; ++j) {
        int distance = 0;
        for (int i = 0; i < 1000000; ++i) {
            if (rand() % 2) distance++;
            else distance--;
            if (distance >= 1000) {
                lose++;
                break;
            }
        }
    }

    printf("%d", lose);

}