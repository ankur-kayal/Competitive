t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    winner = "Second"
    moves = 0
    for index,i in enumerate(a):
        if index + 1 < i:
            moves = 0
            break
        else:
            moves += i - index - 1
    if moves % 2 == 1:
        winner = "First"
    print(winner)