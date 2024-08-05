//
// Created by Jiang Yinzuo on 2020/4/30.
//

#include <stdio.h>

/**
 * 非递归二分
 * @param arr 查找的数组
 * @param start 数组开始下标
 * @param end 数组结束下标
 * @param value 待查找的值
 * @return 找到就返回数组下标，没找到返回-1
 */
//int bin_search(int arr[], int start, int end, int value) {
//    while (start <= end) {
//        int mid = (start + end) / 2;
//        if (value == arr[mid]) return mid;
//        else if (arr[mid] > value) start = mid + 1;
//        else end = mid - 1;
//    }
//
//    return -1;
//}

/**
 * 递归二分
 * @param arr 查找的数组
 * @param start 数组开始下标
 * @param end 数组结束下标
 * @param value 待查找的值
 * @return 找到就返回数组下标，没找到返回-1
 */
int bin_search(int arr[], int start, int end, int value) {
    if (start == end) {
        if (arr[start] == value) return start;
        return -1;
    }

    int mid = (start + end) / 2;
    if (arr[mid] == value) return mid;
    else if (arr[mid] > value) return bin_search(arr, mid + 1, end, value);
    else return bin_search(arr, start, mid - 1, value);
}

int main() {
    int arr[] = {10, 4, 2, 1, 0};
    int res = bin_search(arr, 0, 3, 7);
    printf("%d\n", res);
    return 0;
}