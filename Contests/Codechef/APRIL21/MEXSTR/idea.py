def contains_subsequence(big, small):
    m = len(big)
    n = len(small)

    L = [[0 for _ in range(n + 2)] for _ in range(m + 2)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0:
                L[i][j] = 0
            elif big[i - 1] == small[j - 1]:
                L[i][j] = L[i - 1][j - 1] + 1
            else:
                L[i][j] = max(L[i - 1][j], L[i][j - 1])

    return L[m][n] < n

t = int(input())
for _ in range(t):
    s = input()
    for i in range(len(s)):
        sub = s[len(s)-i-1:]
        compress = []

        ls = len(sub)
        c = 0
        prev = sub[0]
        for i in sub:
            if i == prev:
                c+=1
            else:
                compress.append([c, prev])
                c = 1
                prev = i

        compress.append([c, prev])
        for j in range(10**9):
            if contains_subsequence(sub, bin(j)[2:]):
                ans = j
                break
        print(sub, '\n', compress,'\n', bin(ans)[2:], '\n')
