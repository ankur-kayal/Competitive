#!/usr/bin/env python

# pyrival template for speed. Link -> https://raw.githubusercontent.com/cheran-senthil/PyRival/master/templates/template_py3.py
import os
import sys
from io import BytesIO, IOBase


# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion

def calculate_score(n, order):
    total = n
    score = 0
    for price, quantity in order:
        score += min(total, quantity) * price
        total -= min(total, quantity)
    return score


inf = 10**36
t = int(input())
for _ in range(t):
    N,E,H,A,B,C = map(int,input().split())
    

    ans = inf

    for cake in range(min(E,H,N) + 1):
        remaining_egg = E - cake
        remaining_chocolate = H - cake
        order = [[A, remaining_egg // 2], [B, remaining_chocolate // 3], [C, cake]]
        order.sort()
        if order[0][1] + order[1][1] + order[2][1] >= N:
            ans = min(ans, calculate_score(N, order))
            # print(order, score)
    if ans == inf:
        print(-1)
    else:
        print(ans)