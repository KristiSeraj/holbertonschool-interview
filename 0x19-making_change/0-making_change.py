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

    coins.sort(reverse=True)

    count = 0
    i = 0

    while total > 0 and i < len(coins):
        if coins[i] <= total:
            numCoins = total // coins[i]
            count += numCoins
            total -= numCoins * coins[i]
        i += 1

    return count if total == 0 else -1
