//
// Created by Jiang Yinzuo on 2020/5/2.
//

#include <algorithm>
#include <cstdio>

int arr[100009];
long long left_sum[100009];
long long right_sum[100009];

int n;

long long get_left_dis(int l, int idx) {

  if (idx == 0)
    return 0;
  return left_sum[idx - 1] + idx * (l - arr[idx - 1]);
}

long long get_right_dis(int l, int idx) {
  if (idx == n) {
    return 0;
  }
  return right_sum[idx] + (n - idx) * (arr[idx] - l);
}

int main() {
  int q;
  scanf("%d %d", &n, &q);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    right_sum[0] += arr[i];
  }
  std::sort(arr, arr + n);
  right_sum[0] -= arr[0] * n;
  left_sum[0] = 0;
  for (int i = 1; i < n; ++i) {
    left_sum[i] = left_sum[i - 1] + i * (arr[i] - arr[i - 1]);
    right_sum[i] = right_sum[i - 1] + (i - n) * (arr[i] - arr[i - 1]);
  }

  int l, r;

  long long result;
  int mid;
  int lidx;
  int ridx;
  int midx;
  while (q--) {
    scanf("%d %d", &l, &r);
    lidx = std::lower_bound(arr, arr + n, l) - arr;
    ridx = std::lower_bound(arr, arr + n, r) - arr;
    mid = (l + r) / 2;
    midx = std::lower_bound(arr, arr + n, mid) - arr;
    if (l == r) {
      printf("%lld\n", get_left_dis(l, lidx) + get_right_dis(l, lidx));
    } else {
      if (l < r) {
        int temp = l;
        l = r;
        r = temp;
      }

      result = get_left_dis(r, ridx) + get_right_dis(l, lidx) +
               get_right_dis(r, ridx) - get_right_dis(mid, midx) +
               get_left_dis(l, lidx) - get_left_dis(mid, midx) -
               (ridx - midx) * (r - mid) - (midx - lidx) * (mid - l);
      printf("%lld\n", result);
    }
  }
  return 0;
}