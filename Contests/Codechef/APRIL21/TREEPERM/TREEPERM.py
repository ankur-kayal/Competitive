t = int(input())
for _ in range(t):
    n, s = map(int,input().split())
    for i in range(n-1):
        u, v = map(int,input().split())

    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    a.sort()
    b.sort()
    if a == b:
        print(1)
    else:
        print(0)