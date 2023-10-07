t = int(input())
for test in range(1, t + 1):
    s = "Case #" + str(test) + ":"
    print(s, end=" ")

    N,A,B = map(int,input().split())
    U = list(map(int,input().split()))

    last = 0
    for i in range(1, N + 1):
        if U[i-1] != 0:
            last = i;


    def valid(M):
        alchemy = [0 for i in range(M + 1)]
        alchemy[M] = 1
        for i in range(1, N + 1):
            alchemy[i] -= U[i - 1]

        for j in range(M, 0, -1):
            if alchemy[j] < 0:
                return False
            if j - A > 0:
                alchemy[j - A] += alchemy[j]

            if j - B > 0:
                alchemy[j - B] += alchemy[j]

        return True
    ans = "IMPOSSIBLE"
    for i in range(last + 1, 403):
        if valid(i):
            ans = i
            # print(i)
            break

    print(ans)

    