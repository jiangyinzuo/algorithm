//
// Created by Jiang Yinzuo on 2022/2/12.
//

#include <cstdio>
#include <cstdlib>

static char s1[300009], s2[300009], s3[300009];

int hanming_distance(char *str1, char *str2) {
	int answer = 0;
	while (*str1) {
		answer += (*str1++ != *str2++);
	}
	return answer;
}

void print_answer(int n, char *str1, char *str2) {
	int count = 0;
	while (*str1) {
		if (*str1 == *str2) {
			putchar(*str1);
			++count;
		} else {
			putchar(*str1);
			putchar(*str2);
			count += 2;
		}
		++str1;
		++str2;
	}
	for (;count < 3 * n; ++count) {
		putchar('0');
	}
	putchar('\n');
}

void solve(int n) {
	if (int dis1_2 = hanming_distance(s1, s2); dis1_2 <= n) {
		return print_answer(n, s1, s2);
	}
	if (int dis2_3 = hanming_distance(s2, s3); dis2_3 <= n) {
		return print_answer(n, s2, s3);
	}
	if (int dis1_3 = hanming_distance(s1, s3); dis1_3 <= n) {
		return print_answer(n, s1, s3);
	}
	// error
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