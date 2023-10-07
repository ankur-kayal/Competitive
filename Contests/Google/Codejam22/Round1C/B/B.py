t = int(input())
for test in range(1, t + 1):
    s = "Case #" + str(test) + ":"
    print(s, end=" ")

    y = int(input())
    ys = str(y)

    a = []

    ans = ""
    for i in ys:
        ans = ans + i
        tmp = ans
        for j in range(int(tmp) + 1, 10**26):
            tmp += str(j)
            a.append(int(tmp))
            if len(tmp) > 20:
                break

    ys = str(int(ys[0]) + 1) + ys[1:]
    ans = ""
    for i in ys:
        ans = ans + i
        tmp = ans
        for j in range(int(tmp) + 1, 10**26):
            tmp += str(j)
            a.append(int(tmp))
            if len(tmp) > 20:
                break

    m = 1;
    while m <= 10**18:
        tmp = str(m)
        for j in range(m + 1, 10**26):
            tmp += str(j)
            a.append(int(tmp))
            if len(tmp) > 20:
                break
        m *= 10

    a.sort()
    res = 0
    for i in a:
        if i > y:
            res = i
            break

    print(res)