t = int(input())
for i in range(t):
    print("case : ", i)
    x,y,n = map(int, input().split())
    for i in range(n + 1):
        if x ^ i < y ^ i:
            print(bin(x)[2:], bin(y)[2:], bin(i)[2:])