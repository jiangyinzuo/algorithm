//
// Created by jiang on 2020/8/15.
// poj 1811 Prime Test

#include <iostream>
#include <ctime>
#include <algorithm>
#include <map>

#define TEST_TIMES 8 // 米勒罗宾素性测试次数

std::map<long long, int> factor_nums;

/**
 * 快速乘法
 * @param a
 * @param b
 * @param p
 * @return
 */
long long mul(long long a, long long b, long long p) {
    long long ans = 0;
    a %= p;
    while (b) {
        if (b & 1)ans = (ans + a) % p;
        b /= 2;
        a = (a + a) % p;
    }
    return ans;
}

/**
 * 快速幂取模
 * @param a
 * @param b
 * @param p
 * @return
 */
long long pow(long long a, long long b, long long p) {
    long long ans = 1;
    a %= p;
    while (b) {
        if (b & 1) ans = mul(a, ans, p);
        b /= 2;
        a = mul(a, a, p);
    }
    ans %= p;
    return ans;
}

/**
 * 米勒罗宾素性测试
 * @param n 测试的大数
 * @param repeat 测试重复次数
 * @return 大概率是素数：true；不是素数：false
 */
bool miller_rabin(long long n, int repeat) {
    if (n == 2 || n == 3)return true;//特判
    if (n % 2 == 0 || n == 1)return false;//偶数和1

    //将n-1分解成2^s*d
    long long d = n - 1;
    int s = 0;
    while (!(d & 1)) ++s, d >>= 1;
    //srand((unsigned)time(NULL));在最开始调用即可
    for (int i = 0; i < repeat; i++) { //重复repeat次
        long long a = rand() % (n - 3) + 2;//取一个随机数,[2,n-1)
        long long x = pow(a, d, n);
        long long y = 0;
        for (int j = 0; j < s; j++) {
            y = mul(x, x, n);
            if (y == 1 && x != 1 && x != (n - 1))return false;
            x = y;
        }
        if (y != 1)return false; //费马小定理
    }
    return true;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

/**
 * 找到n的一个因子
 * @param n
 * @param c
 * @return
 */
long long pollard_rho(long long n, long long c) {
    long long x = rand() % (n - 2) + 1;
    long long y = x, i = 1, k = 2;
    for (;;) {
        i++;
        x = (mul(x, x, n) + c) + n;//不断调整x2
        long long d = gcd(y - x, n);
        if (1 < d && d < n)
            return d;//找到因子
        if (y == x)
            return n;//找到循环，返回n，重新来
        if (i == k) { //一个优化
            y = x;
            k <<= 1;
        }
    }
}


void find_factor(long long n, long long c) {
    if (n == 1)return;//递归出口

    if (miller_rabin(n, TEST_TIMES)) { //如果是素数，就加入
        factor_nums[n]++;
        return;
    }

    long long p = n;
    while (p >= n)
        p = pollard_rho(p, c--);//不断找因子，知道找到为止，返回n说明没找到

    find_factor(p, c);
    find_factor(n / p, c);
}

int main() {
    long long n;
//    srand(time(NULL));  有的OJ似乎要去掉这句话
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        factor_nums.clear();
        find_factor(n, rand() % (n - 1) + 1);
        if (factor_nums.begin()->first == n) {
            std::cout << "Prime" << std::endl;
        } else
            std::cout << factor_nums.begin()->first << std::endl;
    }
    return 0;
}