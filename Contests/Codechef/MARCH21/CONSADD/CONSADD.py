inf = 10**18
t = int(input())
for _ in range(t):
    r,c,x = map(int,input().split())

    A = []
    for _ in range(r):
        tmp = list(map(int,input().split()))
        A.append(tmp)

    B = []
    for _ in range(r):
        tmp = list(map(int,input().split()))
        B.append(tmp)



    diffs = []
    for i in range(r):
        tmp = []
        for j in range(c):
            tmp.append(-A[i][j] + B[i][j])
        diffs.append(tmp)



    # Normalize all rows brute force
    for i in range(r):
        for j in range(c-x+1):
            val = diffs[i][j]
            if val == 0:
                continue
            for k in range(j, j + x):
                diffs[i][k] -= val

    #Normalize all columns brute force

    for j in range(c):
        for i in range(r-x+1):
            val = diffs[i][j]
            if val == 0:
                continue
            for k in range(i, i + x):
                diffs[k][j] -= val

    total_sum = 0
    for i in diffs:
        for j in i:
            total_sum += abs(j)

    if total_sum == 0:
        print("Yes")
    else:
        print("No")     
