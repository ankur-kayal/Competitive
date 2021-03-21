import math
t = int(input())
for tt in range(t):
    # print("Test Case: #", tt + 1)
    n = int(input())
    h = list(map(int,input().split()))
    stars = []
    stars.append([h[0], 0])
    answer = 1
    for i in range(1, n):
        while len(stars) > 0 and stars[-1][0] < h[i]:
            stars.pop()
            # print(stars)
        while len(stars) >= 2:
            y1,x1 = stars[-2]
            y2,x2 = stars[-1]
            y3,x3 = h[i],i 
            slope1 = math.atan((y1 - y2) / (x1 - x2))
            slope2 = math.atan((y2 - y3) / (x2 - x3))
            # print(slope1, slope2)
            if(slope2 >= slope1):
                stars.pop()
            else:
                break
        stars.append([h[i], i])
        # print(stars)
        if len(stars) >= 2:
            answer = max(answer, abs(stars[-1][1] - stars[-2][1]))

    stars = []
    stars.append([h[n-1], n-1])
    for i in range(n-2, -1, -1):
        while len(stars) > 0 and stars[-1][0] < h[i]:
            stars.pop()

        while len(stars) >= 2:
            y1,x1 = stars[-2]
            y2,x2 = stars[-1]
            y3,x3 = h[i],i
            slope1 = math.atan((y1 - y2) / (x1 - x2))
            slope2 = math.atan((y2 - y3) / (x2 - x3))
            # print(slope1, slope2)
            if(slope2 <= slope1):
                stars.pop()
            else:
                break
        stars.append([h[i], i])
        # print(stars)
        if len(stars) >= 2:
            answer = max(answer, abs(stars[-1][1] - stars[-2][1]))
    print(answer)