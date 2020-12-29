n = int(input(), 2)
ans = 0;
while(n != 1):
    if n & 1:
        n+=1
    else:
        n //= 2
    ans+=1
print(ans)