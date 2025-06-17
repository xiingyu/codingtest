import sys

n,m = map(int,sys.stdin.readline().split())

A = []
B = []
for _ in range(n) :
    A.append(list(map(int,sys.stdin.readline().split())))

m,k = map(int,sys.stdin.readline().split())
for _ in range(m) :
    B.append(list(map(int,sys.stdin.readline().split())))
    
results = [[0 for _ in range(k)] for _ in range(n)]
        
for col in range(k) :
    for row in range(n) :
        temp = 0
        for num in range(m) :
            temp += A[row][num] * B[num][col]
        results[row][col] = temp
        
for arr in results :
    print(" ".join(map(str,arr)))
        