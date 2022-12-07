#!/usr/bin/python3
"""Unlock module"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    new_list = []
    new_list.append(boxes[0][0])
    ls = []

    for i in range(len(boxes)):
        if i in new_list:
            for j in range(len(boxes[i])):
                if boxes[i][j] not in new_list:
                    new_list.append(boxes[i][j])
                    if boxes[i][j] < i:
                        for n in boxes[boxes[i][j]]:
                            if n < len(boxes):
                                if boxes[n] not in new_list:
                                    ls.append(n)
    for i in ls:
        new_list.append(i)
    new_list = set(new_list)
    return len(new_list) == len(boxes)
