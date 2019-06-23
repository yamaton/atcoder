import sys

prev = None
for c in input().strip():
    if c == prev:
        print("Bad")
        sys.exit()
    prev = c
print("Good")
