def generate(s, n):
    power = set()

    def generate_subsequences(s, n, index=-1, curr=""):
        if index == n:
            return
        if len(curr) > 0:
            power.add(int(curr, 2))

        for i in range(index + 1, n):
            curr += s[i]
            generate_subsequences(s, n, i, curr)
            curr = curr[:len(curr)-1]
        return

    generate_subsequences(s, n)
    return power

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

    compress = []

    ls = len(s)
    c = 0
    prev = s[0]
    for i in s:
        if i == prev:
            c+=1
        else:
            compress.append([c, prev])
            c = 1
            prev = i

    compress.append([c, prev])
    # print(compress)

    threshold = 10

    ans = ""
    if len(compress) <= threshold:
        for j in range(10**9):
            if contains_subsequence(s, bin(j)[2:]):
                ans = bin(j)[2:]
                break

    else:
        pos = -1
        compress.reverse()
        first = []
        last = []
        if compress[threshold-1][1] == '0':
            last = compress[:threshold]
            first = compress[threshold:]
        else:
            last = compress[:threshold+1]
            first = compress[threshold+1:]
        last.reverse()
        first.reverse()

        back = ""
        for i in last:
            for j in range(i[0]):
                back += i[1]

        ans_last = ""
        for j in range(10**9):
            if contains_subsequence(back, bin(j)[2:]):
                ans_last = bin(j)[2:]
                break

        ans_first = ""
        for i in range(len(first)):
            if first[i][1] == '1':
                if first[i][0] == 1:
                    ans_first += '1'
                else:
                    ans_first += '10'
        print(ans_first, ans_last)
        ans = ans_first + ans_last
        ans2 = '1' + '0' * (s.count('0') + 1)
        if len(ans) >= len(ans2):
            ans = ans2



    print(ans)