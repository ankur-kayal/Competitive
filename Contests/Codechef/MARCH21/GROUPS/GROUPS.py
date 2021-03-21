t = int(input())
for _ in range(t):
    s = input() + '0'

    groups = 0

    is_group = False

    for i in s:
        if i == '1':
            is_group = True
        else:
            if is_group:
                groups+=1
                is_group = False

    print(groups)