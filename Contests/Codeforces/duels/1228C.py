x,n = map(int,input().split())

prime_factors = []

for i in range(2, int(x ** 0.5) + 1):
    if x % i == 0:
        prime_factors.append(i)
        while x % i == 0:
            x = x // i 


if x > 1:
    prime_factors.append(x)

ans = 1

mod = int(1e9) + 7
# print(mod)

# print(prime_factors)

for i in prime_factors:
    base = i
    while base <= n:
        ans = (ans * pow(i, n // base, mod)) % mod
        base = base * i
        # print(ans)

print(ans)