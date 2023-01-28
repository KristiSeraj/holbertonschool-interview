#!/usr/bin/python3
"""Stats module used for log parsing"""
import sys
import re
from collections import Counter

total_size = 0
status_codes = Counter()

pattern = re.compile(r"(\d+\.\d+\.\d+\.\d+) - \[.+\] \"GET /projects/\d+ HTTP/1\.1\" (\d+) (\d+)")

try:
    for i, line in enumerate(sys.stdin):
        match = pattern.match(line)
        if not match:  # skipping invalid lines
            continue
        _, status_code, file_size = match.groups()
        total_size += int(file_size)
        status_codes[status_code] += 1

        if (i + 1) % 10 == 0:
            print("File size:", total_size)
            for code in sorted(status_codes.keys()):
                print(f"{code}: {status_codes[code]}")

except KeyboardInterrupt:
    print("File size:", total_size)
    for code in sorted(status_codes.keys()):
        print(f"{code}: {status_codes[code]}")
