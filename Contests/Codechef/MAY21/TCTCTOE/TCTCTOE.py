T = int(input())
for i in range(T):
    cx = 0
    co = 0
    n = 0

    l = []
    for i in range(3):
        tic = input()
        l.append(tic)

    for i in range(3):
        for j in range(3):
            if l[i][j] == 'X':
                cx += 1
            elif l[i][j] == 'O':
                co += 1
            else:
                n += 1

    wx = 0
    wo = 0

    if l[0][0] == 'X'