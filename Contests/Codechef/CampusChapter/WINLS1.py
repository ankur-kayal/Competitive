n = int(input())
val = [i for i in range(1 , n + 1)]

q = int(input())
for _ in range(q):
    target = int(input())
    ans = 0
    index = -1
    for i in range(n):
        if val[i] != target:
            ans+=1
        else:
            index = i
            break
    print(ans, end=" ")
    val = [target] + val[0:index] + val[index + 1: ] 

