#!/usr/bin/python3
"""Make change module"""
import sys


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total
    Returns fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0

    table = [float('inf')] * (total + 1)
    table[0] = 0

    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                sub_res = table[i - coin]
                if sub_res != float('inf') and sub_res + 1 < table[i]:
                    table[i] = sub_res + 1

    if table[total] == float('inf'):
        return -1

    return table[total]
