t = int(input())
for _ in range(t):
    n = int(input())
    hashed = [{} for i in range(26)]
    names = list(input().split())
    for name in names:
        index = ord(name[0]) - ord('a')
        # print(ord(name[0]), ord('a'), name[0])
        if hashed[index].get(name[1:], -1) == -1:
            hashed[index][name[1:]] = 0
        hashed[index][name[1:]] += 1


    # print(hashed)

    teamnames = 0
    for i in range(26):
        for j in range(26):
            if i != j:
                for first_name in hashed[i]:
                    if hashed[j].get(first_name, -1) ==  -1:
                        for last_name in hashed[j]:
                            if hashed[i].get(last_name, -1) == -1:
                                teamnames += hashed[i].get(first_name) * hashed[j].get(last_name)


    print(teamnames)
