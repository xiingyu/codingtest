import sys

arr = []
result = []
max_len = 0
for _ in range(5) :
    arr.append(sys.stdin.readline().strip())
    if len(arr[-1]) >= max_len :
        max_len = len(arr[-1])

for col in range(max_len) :
    for row in range(5) :
        if len(arr[row]) <= col :
            continue
        else :
            result.append(arr[row][col])

print("".join(map(str,result)))

