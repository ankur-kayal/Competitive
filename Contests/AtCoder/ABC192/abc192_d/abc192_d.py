import sys


x = input()
m = int(input())
ans = 0
y = sorted(x, reverse = True)
x = x[::-1]
base = int(y[0]) + 1
lower = 1
upper = 10**18 + 100

if len(x) == 1:
    if int(x) > m:
        print(0)
    else:
        print(1)
    sys.exit(0)

def verify(mid):
    val = 0
    # print(x)
    np = 1
    ok = True
    for i in x:
        # print("i = ", i)
        val+=int(i) * np
        np *= mid
    # print(val, base)
    return val <= m

while(upper > lower + 1):
    mid = (lower + upper) // 2
    if verify(mid):
        lower = mid
    else:
        upper = mid

print(max(lower - base + 1, 0))


# verify(10)
# print(ans)