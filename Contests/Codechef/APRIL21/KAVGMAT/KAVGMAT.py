t = int(input())
for _ in range(t):
    row, col, k = map(int, input().split())
    a = [[0 for _ in range(col + 2)] for _ in range(row + 2)]


    for i in range(1, row + 1):
        tmp = list(map(int, input().split()))
        tmp = [0] + tmp + [0]
        a[i] = tmp


    # first cumulative row addition for rows bottom up

    for i in range(row, 0, -1):
        for j in range(col, 0, -1):
            a[i][j] += a[i + 1][j]

    # second cumulative column addition from right to left
    for i in range(row, 0, -1):
        for j in range(col, 0, -1):
            a[i][j] += a[i][j + 1]

    ans = 0

    for i in range(1, row + 1):
        for j in range(1, col + 1):
            l = -1
            increment = min(row - i, col - j)
            r = increment + 1

            while(r > l + 1):
                m = (l + r) // 2
                score = a[i][j] + a[i + m + 1][j + m + 1] - a[i + m + 1][j] - a[i][j + m + 1]
                elements = (m + 1) * (m + 1)
                if score >= k * elements:
                    r = m
                else:
                    l = m
            ans += max(0, increment - r + 1)
    
    print(ans)