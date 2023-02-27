#!/usr/bin/python3
"""Minimum operations"""


def countProcess(num):
    """Counts n H"""
    c = 1
    proces_list = []
    value = num
    while value != 1:
        c += 1
        if value % c == 0:
            while (value % c == 0 and value != 1):
                value /= c
                proces_list.append(c)

    return proces_list


def minOperations(n):
    """Sum of process untin n H """
    if n < 2 or type(n) is not int:
        return 0
    values = countProcess(n)
    return sum(values)
