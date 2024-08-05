# -*- coding: utf-8 -*-
"""
diff module
"""
from typing import List, AnyStr, Tuple, Set

__all__ = ['diff']


def _get_lcs(s1: List[AnyStr], s2: List[AnyStr]) -> Tuple[Set[int], Set[int]]:
    """
    Get longest common subsequence (lcs)
    :param s1: subsequence1
    :param s2: subsequence2
    :return: lcs tuple which is composed of indexes in s1 and s2
    """
    f: List[List[int]] = [[0] * (len(s2) + 1) for _ in range(len(s1) + 1)]
    for i in range(1, len(s1) + 1):
        for j in range(1, len(s2) + 1):
            f[i][j] = f[i - 1][j - 1] + 1 if s1[i - 1] == s2[j - 1] else max(f[i][j - 1], f[i - 1][j])

    i: int = len(s1)
    j: int = len(s2)
    result_s1: set = set()
    result_s2: set = set()
    while i and j:
        if s1[i - 1] == s2[j - 1]:
            result_s1.add(i)
            result_s2.add(j)
            i -= 1
            j -= 1
        elif f[i][j - 1] > f[i - 1][j]:
            j -= 1
        else:
            i -= 1
    return result_s1, result_s2


def diff(old_filename: str, new_filename: str) -> None:
    """
    Based on Myers Difference Algorithm.
    """
    with open(old_filename) as f_old, open(new_filename) as f_new:
        old_lines: List[AnyStr] = f_old.readlines()
        new_lines: List[AnyStr] = f_new.readlines()

        lcs = _get_lcs(old_lines, new_lines)

        deletion_set = set(range(1, len(old_lines) + 1)) - lcs[0]
        addition_set = set(range(1, len(new_lines) + 1)) - lcs[1]

        print(lcs)
        print('{} additions, {} deletions.'.format(len(addition_set), len(deletion_set)))
        print('deletions in `{}`:'.format(old_filename))
        print('line {}'.format(deletion_set if deletion_set else '{}'))
        print('additions in `{}`:'.format(new_filename))
        print('line {}'.format(addition_set if addition_set else '{}'))


if __name__ == '__main__':
    diff('a.txt', 'b.txt')
