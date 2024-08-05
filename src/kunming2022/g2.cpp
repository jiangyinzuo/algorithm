//
// Created by Jiang Yinzuo on 2022/2/12.
//
#include <cstdio>
#include <algorithm>

static char s1[300009], s2[300009], s3[300009];

int str_sum(char *s) {
	int ans = 0;
	while (*s) {
		ans += *s - '0';
		++s;
	}
	return ans;
}

void insert(int n, char *str1, char *str2) {
	int count = 0;
	for (; *str1 && *str2; ++count) {
		if (*str1 == *str2) {
			putchar(*str1);
			++str1;
			++str2;
		} else {
			putchar(*str1++);
		}
	}
	for (; *str2; ++count) {
		putchar(*str2++);
	}

	for (; count < 3 * n; ++count) putchar('0');
	putchar('\n');
}

void Insert(int n, int s1_sum, int s2_sum, char *str1, char *str2) {
	if (s1_sum < s2_sum) {
		insert(n, str1, str2);
	} else {
		insert(n, str2, str1);
	}
}

void solve(int n) {
	int s1_sum = str_sum(s1);
	int s2_sum = str_sum(s2);
	int s3_sum = str_sum(s3);
	if (std::abs(s1_sum - s2_sum) <= n) {
		return Insert(n, s1_sum, s2_sum, s1, s2);
	}
	if (std::abs(s1_sum - s3_sum) <= n) {
		return Insert(n, s1_sum, s3_sum, s1, s3);
	}
	if (std::abs(s2_sum - s3_sum) <= n) {
		return Insert(n, s2_sum, s3_sum, s2, s3);
	}
	exit(-1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		scanf("%s", s1);
		scanf("%s", s2);
		scanf("%s", s3);
		solve(n);
	}
	return 0;
}
