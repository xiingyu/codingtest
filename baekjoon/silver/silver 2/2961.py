import sys

n = int(sys.stdin.readline().strip())
ingre = []

for i in range(n) :
    ingre.append(list(map(int,sys.stdin.readline().split())))

result = float('inf')

visited = [False for _ in range(n)]
picked=[]
# cnt = 0
def cal(arr) :
    # global cnt
    # cnt += 1
    a,b = 0,0
    for S,B in arr :
        if a == 0 :
            a = S
        else :
            a*=S
        b+= B
    # print(a,b)
    return abs(a-b)



def min_(arr, num,start) :
    global result, visited

    for i in range(start,n) :
        if visited[i] == False :
            picked.append(arr[i])
            visited[i] = True
        else :
            continue
        
        if len(picked) >= num :
            result = min(result, cal(picked))

        else :
            min_(arr,num, i+1)
        
        picked.pop()
        visited[i] = False

        if result == 0 :
            break


for i in range(1,n+1) :
    # print(i)
    min_(ingre,i,0)
    # print(result)

print(result)