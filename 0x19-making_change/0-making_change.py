#!/usr/bin/python3
"""Make change module"""
import sys


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total
    Returns fewest number of coins needed to meet total
    """
    table = [float('inf')] * (total + 1)
    table[0] = 0

    for i in range(total + 1):
        for coin in reversed(coins):
            if coin <= i:
                table[i] = min(table[i], table[i - coin] + 1)
            else:
                break

    return table[total] if table[total] != float('inf') else -1
