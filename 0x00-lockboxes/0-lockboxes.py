#!/usr/bin/python3

def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    new_list = [0]
    for key, value in enumerate(boxes):
        for a_key in value:
            if a_key < len(boxes) and a_key not in new_list and a_key != key:
                new_list.append(a_key)
    return len(new_list) == len(boxes)
