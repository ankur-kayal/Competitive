import sys 
# For getting input from input.txt file 
sys.stdin = open('input.txt', 'r')  
  
# Printing the Output to output.txt file 
sys.stdout = open('output.txt', 'w') 

for _ in range(int(input())):
    n, k = map(int, input().split())
    f = list(map(int, input().split()))
    i = 0
    if k == 1:
        l = []
        l1 = []
        while i < n:
            if f[i] not in l1:
                l1.append(f[i])
                if i == n - 1:
                    l.append(l1)
                    l1.clear()
                i += 1
            else:
                l.append(l1)
                l1.clear()
        k = len(l) * k
        l.clear()
        print(k, end="\n")
    else:
        coun = 0
        s = set(f)
        li = list(s)
        for i in range(len(li)):
            if f.count(li[i]) > 1:
                t = f.count(li[i])
                coun = coun + t
        k = k + coun
        li.clear()
        print(k, end="\n")