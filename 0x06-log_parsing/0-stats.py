#!/usr/bin/python3

"""
Stats module used for log parsing and printing the output

This module takes the logs as input and parses the logs to get the total size
of the files and the count of different status codes.
It uses a regular expression to match the lines of the log and
extract the required information. The logs are read from standard input.
The module outputs the total size and the count of each status
code every 10 lines. The output can be stopped by pressing KeyboardInterrupt.
"""

import sys
import re
from collections import Counter


def func():
    """
    This function reads the log lines from the standard input, matches each
    line with a regular expression pattern to extract
    the required information and updates the total size and the count of each
    status code. It prints the current total size and
    the count of each status code every 10 lines.
    """
    total_size = 0
    status_codes = Counter()

    # Compile the regular expression pattern to match the log lines
    pattern = re.compile(r"(\d+\.\d+\.\d+\.\d+) - \[.+\] \"GET /projects/\d+ HTTP/1\.1\" (\d+) (\d+)")

    try:
        # Read the log lines from standard input
        for i, line in enumerate(sys.stdin):
            match = pattern.match(line)
            if not match:  # skipping invalid lines
                continue
            _, status_code, file_size = match.groups()
            total_size += int(file_size)
            status_codes[status_code] += 1

            if (i + 1) % 10 == 0:
                # Print the total size
                # Count of each status code every 10 lines
                print("File size:", total_size)
                for code in sorted(status_codes.keys()):
                    print(f"{code}: {status_codes[code]}")

    except KeyboardInterrupt:
        # Print the final total size and the count of each status code
        print("File size:", total_size)
        for code in sorted(status_codes.keys()):
            print(f"{code}: {status_codes[code]}")


func()
