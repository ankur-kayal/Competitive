t = int(input())
for _ in range(t):
    c = int(input())
    binary_c = bin(c)[2:]
    binary_c = binary_c[::-1]
    no_of_bits = len(binary_c)

    a = 0
    b = 0
    to_distribute = []
    for i in range(no_of_bits):
        if binary_c[i] == '1': 
            to_distribute.append(1 << i)
        else:
            a += 1 << i 
            b += 1 << i 

    to_distribute = to_distribute[::-1]
    for i in to_distribute:
        if a > b:
            b += i 
        else:
            a += i 

    print(a * b)