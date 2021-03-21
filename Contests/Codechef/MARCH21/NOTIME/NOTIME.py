n, H, x = map(int,input().split())
T = list(map(int,input().split()))

ans = "NO"
for i in T:
    if x + i >= H:
        ans = "YES"
    

print(ans)