import sys

n = int(sys.stdin.readline().strip())
ingre = []

for i in range(n) :
    ingre.append(list(map(int,sys.stdin.readline().split())))

result = float('inf')
visited = [False for _ in range(n+1)]
picked=[]

def cal(arr) :
    a,b = 0,0
    for S,B in arr :
        if a == 0 :
            a = S
        else :
            a*=S
        b+= B
    # print(a,b)
    return abs(a-b)



def min_(arr, num) :
    global result, visited

    for i in range(n) :
        if visited[i] == False :
            picked.append(arr[i])
            visited[i] = True
        else :
            continue
        
        if len(picked) >= num :
            result = min(result, cal(picked))

        else :
            pass
        min_(arr,num)
        picked.pop()
        visited[i] = False


for i in range(1,n+1) :
    # print(i)
    min_(ingre,i)
    # print(result)

print(result)