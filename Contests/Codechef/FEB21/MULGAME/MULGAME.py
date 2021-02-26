t = int(input())
for _ in range(t):
    n,q,m = map(int,input().split())
    a = list(map(int, input().split()))
    ans = [0 for i in range(m + 2)]
    memo = {}
    # print(a)

    for _ in range(q):
        l , r = map(int, input().split())
        l -= 1
        r -= 1
        if a[l] > m:
            continue;
        elif a[l] <= m and a[r] > m:
            ans[a[l]]+=1
            ans[m + 1]-=1

        elif a[r] <= m:
            ans[a[l]]+=1
            ans[m + 1]-=1
            if memo.get((a[l], a[r]), -1) == -1:
                memo[(a[l], a[r])] = 0
            memo[(a[l], a[r])] += 1
    
    # print(memo)
    # print(ans)
    for i in memo:
        left = i[0]
        right = i[1]
        value = memo[i]

        if left + right <= m:
            ans[left + right] -= value
        if right + 2 * left <= m:
            ans[right + 2 * left] += value

        tmp = right + 2 * left
        while tmp + right <= m:
            tmp += right
            ans[tmp] -= value
            if tmp + left <= m:
                ans[tmp + left] += value
            tmp += left

    for i in range(1, m + 1):
        ans[i] += ans[i - 1]

    print(max(ans))

