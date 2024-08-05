//
// Created by Jiang Yinzuo on 2020/12/7.
//

#include <cstdio>

int rmb[7]{1, 6, 28, 88, 198, 328, 648};
int coupons[7]{8, 18, 28, 58, 128, 198, 388};

int main() {
    int n, max_coupons = 0;
    scanf("%d", &n);
    for (int i = 0; i <= 0b1111111; ++i) {
        int total_rmb = 0;
        int total_coupons = 0;
        int _j = i;
        for (int idx = 0;_j > 0 && n >= total_rmb;++idx) {
            if (_j & 1) {
                total_rmb += rmb[idx];
                total_coupons += coupons[idx];
            }
            _j >>= 1;
        }
        if (n >= total_rmb && total_coupons > max_coupons) {
            max_coupons = total_coupons;
        }
    }
    printf("%d\n", max_coupons + n * 10);
    return 0;
}