import sys

n = int(sys.stdin.readline().strip())

arr = list(map(int,sys.stdin.readline().split()))
arr.sort()
result = []
mid = 0
if len(arr) % 2 == 1 :
    mid = len(arr) // 2 
    result.append(arr[mid])
    for i in range(mid-1, -1, -1) :
        result.append(arr[i])
        result.append(arr[len(arr)-1-i])
        # result.append([arr[i], arr[len(arr)-1 -i]])
        # result.sort(key = lambda x : x[1])

else :
    mid = len(arr) // 2 -1
    for i in range(mid, -1, -1) :
        result.append(arr[i])
        result.append(arr[len(arr)-1-i])
    result[1], result[0] = result[0], result[1]

cnt = 0
for i in range(len(result)) :
    if i == 0 :
        cnt += result[i]
    else :
        cnt += max(0,(result[i]-result[i-1]))
    # print(cnt)

print(cnt)


