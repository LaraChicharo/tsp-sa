#!/usr/bin/env python3
from random import randint

n = 2017  # number of seeds
m = n * 10  # range of seeds [1, m]

used = [False] * (m + 4)

print(n)
s = ''
for _ in range(n):
    seed = randint(1, m)
    while used[seed]:
        seed = randint(1, m)
    used[seed] = True
    s += str(seed) + ' '
print(s)

