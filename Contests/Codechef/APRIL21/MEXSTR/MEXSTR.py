

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

t = int(input())
for _ in range(t):
    s = input()
    l = len(s)
    power = generate(s, l)
    for i in range(10**9):
        if i not in power:
            print(bin(i)[2:])
            break